/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:41:19 by mgayout           #+#    #+#             */
/*   Updated: 2024/07/04 11:22:32 by aguezzi          ###   ########.fr       */
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
								data->pos.posx,
								data->pos.posy);
	
	return (0);
}

int	draw(t_data *data, int x, int y)
{
	
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.air.mlx_img,
					data->pos.posx,
					data->pos.posy);
	data->pos.posx += x;
	data->pos.posy += y;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.player.mlx_img,
					data->pos.posx,
					data->pos.posy);
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
