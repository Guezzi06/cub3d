/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:33:12 by mgayout           #+#    #+#             */
/*   Updated: 2024/07/02 16:58:35 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

int	free_all(t_data *data)
{
	free_map(&data->map);
	free_img(&data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img.air.mlx_img);
	mlx_destroy_image(data->mlx, data->img.player.mlx_img);
	mlx_destroy_image(data->mlx, data->img.wall.mlx_img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	free_map(t_map **map)
{
	t_map	*tmp;
	
	while (*map)
	{
		tmp = *map;
		*map = (*map)->next;
		free(tmp);
	}
}

void	free_img(t_imgs *img)
{
	free(img->c_wall);
	free(img->e_wall);
	free(img->f_wall);
	free(img->w_wall);
	free(img->n_wall);
	free(img->s_wall);
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
