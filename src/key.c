/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:38:48 by mgayout           #+#    #+#             */
/*   Updated: 2024/07/04 16:10:56 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

int	press_key(int key, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == XK_Escape)
		free_all(data);
	else if (key == XK_w)
		y -= 5;
	else if (key == XK_a)
		x -= 5;
	else if (key == XK_d)
		x += 5;
	else if (key == XK_s)
		y += 5;
	else if (key == XK_Left || key == XK_Right)
		modify_rot(data, key);
	else
		return (0);
	if (walled(data, x, y))  // plus tard, on pourrait avancer un petit peu si jamais on est pas vraiment colle au mur, de la valeur egale a la distance par rapport au mur
		return (0);
	draw(data, x, y);
	return (0);
}

void	modify_rot(t_data *data, int key)
{
	if (key == XK_Left)
		data->pos.rot += ROT_SPEED;
	else
		data->pos.rot -= ROT_SPEED;
	data->pos.dirX = cos(data->pos.rot);
	data->pos.dirY = -sin(data->pos.rot);
}

int	walled(t_data *data, int x, int y)
{
	int		wall;
	
	wall = 0;
	if (x == 0 && y == 0)
		return (0);
	if (x >= 0 && y >= 0)
		wall = check_up_left_wall(data, x, y);
	else if (x >= 0 && y <= 0)
		wall = check_down_left_wall(data, x, y);
	else if (x <= 0 && y >= 0)
		wall = check_up_right_wall(data, x, y);
	else if (x <= 0 && y <= 0)
		wall = check_down_right_wall(data, x, y);
	return (wall);
}

int	check_up_left_wall(t_data *data, int x, int y)
{
	t_map	*tmp;

	tmp = data->map;
	while (tmp)
	{
		if (tmp->content == '1')
		{
			if (x >= 0)
			{
				if (data->pos.posx + 10 <= tmp->x * data->pos.width
					&& data->pos.posy + 10 >= tmp->y * data->pos.height
					&& data->pos.posy <= (tmp->y + 1) * data->pos.height)  // je regarde la gauche de ce mur, si je suis a la meme hauteur et si je suis a sa gauche
				{
					if (data->pos.posx + 10 + x >= tmp->x * data->pos.width)  // cas ou je rentrerai dans le mur si j'avance
						return (1);
				}
			}
			if (y >= 0)
			{
				if (data->pos.posy + 10 <= tmp->y * data->pos.height
					&& data->pos.posx + 10 >= tmp->x * data->pos.width
					&& data->pos.posx <= (tmp->x + 1) * data->pos.width)  // je regarde le haut de ce mur, si je suis a la meme abscisse et si je suis au-dessus
				{
					if (data->pos.posy + 10 + y >= tmp->y * data->pos.height)  // cas ou je rentrerai dans le mur si j'avance
						return (1);
				}
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_down_left_wall(t_data *data, int x, int y)
{
	t_map	*tmp;

	tmp = data->map;
	while (tmp)
	{
		if (tmp->content == '1')
		{
			if (x >= 0)
			{
				if (data->pos.posx + 10 <= tmp->x * data->pos.width
					&& data->pos.posy + 10 >= tmp->y * data->pos.height
					&& data->pos.posy <= (tmp->y + 1) * data->pos.height)  // je regarde la gauche de ce mur, si je suis a la meme hauteur et si je suis a sa gauche
				{
					if (data->pos.posx + 10 + x >= tmp->x * data->pos.width)  // cas ou je rentrerai dans le mur si j'avance
						return (1);
				}
			}
			if (y <= 0)
			{
				if (data->pos.posy >= (tmp->y + 1) * data->pos.height
					&& data->pos.posx + 10 >= tmp->x * data->pos.width
					&& data->pos.posx <= (tmp->x + 1) * data->pos.width)  // je regarde le bas de ce mur, si je suis a la meme abscisse et si je suis en-dessous
				{
					if (data->pos.posy + y <= (tmp->y + 1) * data->pos.height)  // cas ou je rentrerai dans le mur si j'avance
						return (1);
				}
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_up_right_wall(t_data *data, int x, int y)
{
	t_map	*tmp;

	tmp = data->map;
	while (tmp)
	{
		if (tmp->content == '1')
		{
			if (x <= 0)
			{
				if (data->pos.posx >= (tmp->x + 1) * data->pos.width
					&& data->pos.posy + 10 >= tmp->y * data->pos.height
					&& data->pos.posy <= (tmp->y + 1) * data->pos.height)  // je regarde la droite de ce mur, si je suis a la meme hauteur et si je suis a sa droite
				{
					if (data->pos.posx + x <= (tmp->x + 1) * data->pos.width)  // cas ou je rentrerai dans le mur si j'avance
						return (1);
				}
			}
			if (y >= 0)
			{
				if (data->pos.posy + 10 <= tmp->y * data->pos.height
					&& data->pos.posx + 10 >= tmp->x * data->pos.width
					&& data->pos.posx <= (tmp->x + 1) * data->pos.width)  // je regarde le haut de ce mur, si je suis a la meme abscisse et si je suis au-dessus
				{
					if (data->pos.posy + 10 + y >= tmp->y * data->pos.height)  // cas ou je rentrerai dans le mur si j'avance
						return (1);
				}
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_down_right_wall(t_data *data, int x, int y)
{
	t_map	*tmp;

	tmp = data->map;
	while (tmp)
	{
		if (tmp->content == '1')
		{
			if (x <= 0)
			{
				if (data->pos.posx >= (tmp->x + 1) * data->pos.width
					&& data->pos.posy + 10 >= tmp->y * data->pos.height
					&& data->pos.posy <= (tmp->y + 1) * data->pos.height)  // je regarde la droite de ce mur, si je suis a la meme hauteur et si je suis a sa droite
				{
					if (data->pos.posx + x <= (tmp->x + 1) * data->pos.width)  // cas ou je rentrerai dans le mur si j'avance
						return (1);
				}
			}
			if (y <= 0)
			{
				if (data->pos.posy >= (tmp->y + 1) * data->pos.height
					&& data->pos.posx + 10 >= tmp->x * data->pos.width
					&& data->pos.posx <= (tmp->x + 1) * data->pos.width)  // je regarde le bas de ce mur, si je suis a la meme abscisse et si je suis en-dessous
				{
					if (data->pos.posy + y <= (tmp->y + 1) * data->pos.height)  // cas ou je rentrerai dans le mur si j'avance
						return (1);
				}
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

/*int	*moove_up(t_data *data, int x, int y)
{
	int	*pos;

	pos = malloc(sizeof(int) * 8);
	if (!pos)
		return (NULL);
	if (((data->pos.moovex + x) % data->pos.width) != 0)
	{
		//printf("moove up 1\n");
		pos[0] = (((data->pos.moovex + x) + (data->pos.posx * data->pos.width)) / data->pos.width);
		pos[2] = pos[0] + 1;
		pos[4] = (((data->pos.moovex + x) + (data->pos.posx * data->pos.width)) / data->pos.width);
		pos[6] = pos[4] + 1;;
	}
	else
	{
		//printf("moove up 2\n");
		pos[0] = (((data->pos.moovex + x) + (data->pos.posx * data->pos.width)) / data->pos.width);
		pos[2] = (((data->pos.moovex + x) + (data->pos.posx * data->pos.width)) / data->pos.width);
		pos[4] = (((data->pos.moovex + x) + (data->pos.posx * data->pos.width)) / data->pos.width);
		pos[6] = (((data->pos.moovex + x) + (data->pos.posx * data->pos.width)) / data->pos.width);
	}
	if (((data->pos.moovey + y) % data->pos.height) != 0)
	{
		//printf("moove up 3\n");
		pos[1] = (((data->pos.moovey + y) + (data->pos.posy * data->pos.height)) / data->pos.height);
		pos[3] = pos[1] + 1;
		pos[5] = pos[1] + 1;
		pos[7] = (((data->pos.moovey + y) + (data->pos.posy * data->pos.height)) / data->pos.height);
	}
	else
	{
		//printf("moove up 4\n");
		pos[1] = (((data->pos.moovey + y) + (data->pos.posy * data->pos.height)) / data->pos.height);
		pos[3] = (((data->pos.moovey + y) + (data->pos.posy * data->pos.height)) / data->pos.height);
		pos[5] = (((data->pos.moovey + y) + (data->pos.posy * data->pos.height)) / data->pos.height);
		pos[7] = (((data->pos.moovey + y) + (data->pos.posy * data->pos.height)) / data->pos.height);
	}
	return (pos);
}

int	*moove_down(t_data *data, int x, int y)
{
	int	*pos;

	pos = malloc(sizeof(int) * 8);
	if (!pos)
		return (NULL);
	if (((data->pos.moovex + x) % data->pos.width) != 0)
	{
		//printf("moove down 1\n");
		pos[0] = (((data->pos.moovex + x) + (data->pos.posx * data->pos.width)) / data->pos.width);
		pos[2] = pos[0] + 1;
		pos[4] = (((data->pos.moovex + x) + (data->pos.posx * data->pos.width)) / data->pos.width);
		pos[6] = pos[4] + 1;
	}
	else
	{
		//printf("moove down 2\n");
		pos[0] = (((data->pos.moovex + x) + (data->pos.posx * data->pos.width)) / data->pos.width);
		pos[2] = (((data->pos.moovex + x) + (data->pos.posx * data->pos.width)) / data->pos.width);
		pos[4] = (((data->pos.moovex + x) + (data->pos.posx * data->pos.width)) / data->pos.width);
		pos[6] = (((data->pos.moovex + x) + (data->pos.posx * data->pos.width)) / data->pos.width);
	}
	if (((data->pos.moovey + y) % data->pos.height) != 0)
	{
		//printf("moove down 3\n");
		pos[1] = (((data->pos.moovey + y) + (data->pos.posy * data->pos.height)) / data->pos.height);
		pos[3] = pos[1] + 1;
		pos[5] = pos[1] + 1;
		pos[7] = (((data->pos.moovey + y) + (data->pos.posy * data->pos.height)) / data->pos.height);
	}
	else
	{
		//printf("moove down 4\n");
		pos[1] = (((data->pos.moovey + y) + (data->pos.posy * data->pos.height)) / data->pos.height);
		pos[3] = (((data->pos.moovey + y) + (data->pos.posy * data->pos.height)) / data->pos.height);
		pos[5] = (((data->pos.moovey + y) + (data->pos.posy * data->pos.height)) / data->pos.height);
		pos[7] = (((data->pos.moovey + y) + (data->pos.posy * data->pos.height)) / data->pos.height);
	}
	return (pos);
}*/
