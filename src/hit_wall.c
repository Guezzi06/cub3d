/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:59:46 by aguezzi           #+#    #+#             */
/*   Updated: 2024/07/12 16:00:38 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

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