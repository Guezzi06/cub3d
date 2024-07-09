/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:41:19 by mgayout           #+#    #+#             */
/*   Updated: 2024/07/09 18:10:57 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

int	first_draw(t_data *data)
{
	t_map	*tmp;

	tmp = data->map;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.back.mlx_img,
								0, 0);
	while (tmp)
	{
		if (tmp->content == '1')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall.mlx_img,
								tmp->x * data->pos.width, tmp->y * data->pos.height);
		tmp = tmp->next;
	}
	data->pos.posx = data->pos.posx * data->pos.width + (data->pos.width / 2) - 5;
	data->pos.posy = data->pos.posy * data->pos.height + (data->pos.height / 2) - 5;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.player.mlx_img,
								(int)data->pos.posx, (int)data->pos.posy);
	calcul_len_rayons(data);
	put_rayons(data);
	put_ray_cam(data);
	
	return (0);
}

void	put_rayons(t_data *data)
{
	double	degre_ref;
	double	delta;
	double	my_dirX;
	double	my_dirY;
	
	degre_ref = -PI / 6;
	delta = (PI / 3) / 60;  // ici delta correspond a 1 degre
	int j = 0;
	while (degre_ref <= PI / 6)
	{
		my_dirX = cos(data->pos.rot + degre_ref);
		my_dirY = -sin(data->pos.rot + degre_ref);
		trace_rayon(data, my_dirX, my_dirY, j);
		degre_ref += delta;
		j++;
	}
}

void	trace_rayon(t_data *data, double dirX, double dirY, int j)
{
	double	xval;  // cette valeur va me permettre de savoir si je dois me decaler d'un pixel ou pas
	double	yval;  // pareil ici pour y
	int		x_int;
	int		y_int;
	int		i;

	xval = 0;
	yval = 0;
	x_int = 0;
	y_int = 0;
	i = 0;
	while (i < (int)data->len_rayons[j])
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.rayon.mlx_img,
								(int)data->pos.posx + 4 + x_int, (int)data->pos.posy + 4 + y_int);
		if (dirX >= 0)
			xval += dirX;
		else
			xval -= dirX;
		if (dirY >= 0)
			yval += dirY;
		else
			yval -= dirY;
		if (xval >= x_int + 1 && dirX >= 0)
			x_int++;
		else if (xval >= abs(x_int) + 1 && dirX <= 0)
			x_int--;
		if (yval >= y_int + 1 && dirY >= 0)
			y_int++;
		else if (yval >= abs(y_int) + 1 && dirY <= 0)
			y_int--;
		i++;
	}
}

void	put_ray_cam(t_data *data)
{
	double	xval;  // cette valeur va me permettre de savoir si je dois me decaler d'un pixel ou pas
	double	yval;  // pareil ici pour y
	int		x_int;
	int		y_int;
	int		i;

	xval = 0;
	yval = 0;
	x_int = 0;
	y_int = 0;
	i = 1;
	while (i <= 20)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.ray_cam.mlx_img,
								(int)data->pos.posx + 4 + x_int, (int)data->pos.posy + 4 + y_int);
		if (data->pos.dirX >= 0)
			xval += data->pos.dirX;
		else
			xval -= data->pos.dirX;
		if (data->pos.dirY >= 0)
			yval += data->pos.dirY;
		else
			yval -= data->pos.dirY;
		if (xval >= x_int + 1 && data->pos.dirX >= 0)
			x_int++;
		else if (xval >= abs(x_int) + 1 && data->pos.dirX <= 0)
			x_int--;
		if (yval >= y_int + 1 && data->pos.dirY >= 0)
			y_int++;
		else if (yval >= abs(y_int) + 1 && data->pos.dirY <= 0)
			y_int--;
		i++;
	}
}

int	draw(t_data *data, double x, double y)
{
	t_map	*tmp;

	tmp = data->map;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.back.mlx_img,
								0, 0);
	while (tmp)
	{
		if (tmp->content == '1')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall.mlx_img,
								tmp->x * data->pos.width, tmp->y * data->pos.height);
		if (ft_strchr("0SWEN", tmp->content))
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.sol.mlx_img,
								tmp->x * data->pos.width, tmp->y * data->pos.height);
		tmp = tmp->next;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.air.mlx_img,
					data->pos.posx, data->pos.posy);
	data->pos.posx += x;
	data->pos.posy += y;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.player.mlx_img,
					(int)data->pos.posx, (int)data->pos.posy);
	put_rayons(data);
	put_ray_cam(data);
	return (0);
}

void	print_square(t_data *data, int x, int y, int color)
{
	int	xmin;
	int	ymin;

	ymin = y * 50;
	while (ymin <= ((y + 1) * 50))
	{
		xmin = x * 50;
		while (xmin <= ((x + 1) * 50))
		{
			mlx_pixel_put(data->mlx, data->mlx_win, xmin, ymin, color);
			xmin++;
		}
		ymin++;
	}
}
