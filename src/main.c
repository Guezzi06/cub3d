/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 08:14:35 by mgayout           #+#    #+#             */
/*   Updated: 2024/07/04 15:43:54 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (1);  // mettre une erreur
	if (argv[1][ft_len(argv[1]) - 4] != '.' || argv[1][ft_len(argv[1]) - 3] != 'c'
		|| argv[1][ft_len(argv[1]) - 2] != 'u' || argv[1][ft_len(argv[1]) - 1] != 'b')
		return (1);  // mettre une erreur
	if (init_arg(&data, argv[1]))
		return (1);
	if (data.map != NULL && !parse_map(&data))
	{
		data.mlx = mlx_init();
		init_img(&data);
		init_game(&data);
	}
	else
	{
		free_map(&data.map);
		free_img(&data.img);
	}
	return (0);
}

int	init_arg(t_data *data, char *file)
{
	data->img.n_wall = NULL;
	data->img.e_wall = NULL;
	data->img.s_wall = NULL;
	data->img.w_wall = NULL;
	data->img.c_wall = NULL;
	data->img.f_wall = NULL;
	if (init_walls(data, file))
		return (1);
	init_map(data, file);
	//print_map(data->map);
	init_data(data);
	return (0);
}

void	init_data(t_data *data)
{
	t_map	*tmp;

	tmp = data->map;
	data->pos.x = 0;
	data->pos.y = 0;
	while (tmp)
	{
		if (tmp->content == 'N' || tmp->content == 'S'
			|| tmp->content == 'E' || tmp->content == 'W')
		{
			init_dir(data, tmp->content);
			data->pos.posx = tmp->x;  // correspond a l'index de la colonne commencant par 0
			data->pos.posy = tmp->y;  // correspond a l'index de la ligne commencant par 0
		}
		if (tmp->x > data->pos.x)
			data->pos.x = tmp->x;
		if (tmp->y > data->pos.y)
			data->pos.y = tmp->y;
		tmp = tmp->next;
	}
	data->pos.xmax = data->pos.x + 1;  // correspond au nombre de colonnes
	data->pos.width = (800 / data->pos.xmax);
	data->pos.ymax = data->pos.y + 1;  // correspond au nombre de lignes
	data->pos.height = (500 / data->pos.ymax);
}

void	init_dir(t_data *data, char content)
{
	if (content == 'N')
	{
		data->pos.rot = PI / 2;
		data->pos.dirX = cos(data->pos.rot);
		data->pos.dirY = -sin(data->pos.rot);
	}
	else if (content == 'S')
	{
		data->pos.rot = -PI / 2;
		data->pos.dirX = cos(data->pos.rot);
		data->pos.dirY = -sin(data->pos.rot);
	}
	else if (content == 'E')
	{
		data->pos.rot = 0.0;
		data->pos.dirX = cos(data->pos.rot);
		data->pos.dirY = -sin(data->pos.rot);
	}
	else if (content == 'W')
	{
		data->pos.rot = PI;
		data->pos.dirX = cos(data->pos.rot);
		data->pos.dirY = -sin(data->pos.rot);
	}
}

void	init_game(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->pos.width * data->pos.xmax, data->pos.height * data->pos.ymax, "cube3D");
	first_draw(data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &press_key, data);
	mlx_hook(data->mlx_win, 17, 0, &free_all, data);
	mlx_loop(data->mlx);
}
