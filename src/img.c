/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:02:36 by mgayout           #+#    #+#             */
/*   Updated: 2024/07/06 16:05:46 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	init_img(t_data *data)
{
	data->img.back.mlx_img = mlx_new_image(data->mlx, 800, 500);
	data->img.back.addr = mlx_get_data_addr(data->img.back.mlx_img, &data->img.back.bpp, &data->img.back.line_len, &data->img.back.endian);
	render_ofback(&data->img.back, 0x444444);
	data->img.wall.mlx_img = mlx_new_image(data->mlx, data->pos.width - 1, data->pos.height - 1);
	data->img.wall.addr = mlx_get_data_addr(data->img.wall.mlx_img, &data->img.wall.bpp, &data->img.wall.line_len, &data->img.wall.endian);
	render_background(data, &data->img.wall, 0xFFFFFF);
	data->img.sol.mlx_img = mlx_new_image(data->mlx, data->pos.width, data->pos.height);
	data->img.sol.addr = mlx_get_data_addr(data->img.sol.mlx_img, &data->img.sol.bpp, &data->img.sol.line_len, &data->img.sol.endian);
	render_background(data, &data->img.sol, 0x444444);
	data->img.player.mlx_img = mlx_new_image(data->mlx, 10, 10);
	data->img.player.addr = mlx_get_data_addr(data->img.player.mlx_img, &data->img.player.bpp, &data->img.player.line_len, &data->img.player.endian);
	render_background(data, &data->img.player, 0xFF0000);
	data->img.air.mlx_img = mlx_new_image(data->mlx, 10, 10);
	data->img.air.addr = mlx_get_data_addr(data->img.air.mlx_img, &data->img.air.bpp, &data->img.air.line_len, &data->img.air.endian);
	render_background(data, &data->img.air, 0x444444);
	data->img.ray_cam.mlx_img = mlx_new_image(data->mlx, 2, 2);
	data->img.ray_cam.addr = mlx_get_data_addr(data->img.ray_cam.mlx_img, &data->img.ray_cam.bpp, &data->img.ray_cam.line_len, &data->img.ray_cam.endian);
	render_background(data, &data->img.ray_cam, 0xCCCC00);
	data->img.rayon.mlx_img = mlx_new_image(data->mlx, 1, 1);
	data->img.rayon.addr = mlx_get_data_addr(data->img.rayon.mlx_img, &data->img.rayon.bpp, &data->img.rayon.line_len, &data->img.rayon.endian);
	render_background(data, &data->img.rayon, 0xFFA500);
}

void	render_ofback(t_texture *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 500)
	{
		j = 0;
		while (j < 800)
		{
			img_pix_put(img, j++, i, color);
		}
		i++;
	}
}

void	render_background(t_data *data, t_texture *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->pos.height)
	{
		j = 0;
		while (j < data->pos.width)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

void	img_pix_put(t_texture *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}