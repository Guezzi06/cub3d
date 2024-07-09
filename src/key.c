/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:38:48 by mgayout           #+#    #+#             */
/*   Updated: 2024/07/09 17:31:57 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

int	press_key(int key, t_data *data)
{
	data->x = 0;
	data->y = 0;
	if (key == XK_Escape)
		free_all(data);
	else if (key == XK_w)  // mettre les bonnes valeurs de x et y en fonction de la direction du joueur
		move_w(data);
	else if (key == XK_a)
		move_a(data);
	else if (key == XK_d)
		move_d(data);
	else if (key == XK_s)
		move_s(data);
	else if (key == XK_Left || key == XK_Right)
		modify_rot(data, key);
	else
		return (0);
	if (walled(data, (int)data->x, (int)data->y))  // plus tard, on pourrait avancer un petit peu si jamais on est pas vraiment colle au mur, de la valeur egale a la distance par rapport au mur
		return (0);
	calcul_len_rayons(data);
	draw(data, data->x, data->y);
	return (0);
}

void	calcul_len_rayons(t_data *data)
{
	double	degre_ref;
	double	delta;
	double	my_dirX;
	double	my_dirY;
	int		i;

	degre_ref = -PI / 6;
	delta = (PI / 3) / 60;  // ici delta correspond a 1 degre
	i = 0;
	while (degre_ref <= PI / 6)
	{
		my_dirX = cos(data->pos.rot + degre_ref);
		my_dirY = -sin(data->pos.rot + degre_ref);
		data->len_rayons[i] = len_collision(data, my_dirX, my_dirY);
		degre_ref += delta;
		i++;
	}
	data->len_rayons[i] = -1;
	int	j = 0;
	int	k = 0;
	while (data->len_rayons[j] != -1)
	{
		printf("%f -- ", data->len_rayons[j]);
		j++;
		k++;
		if (k == 10)
		{
			printf("\n");
			k = 0;
		}
	}
	printf("\n   ---  \n");
}

double	len_collision(t_data *data, double dirX, double dirY)
{
	/* position de depart : x = data->pos.posx + 4
							y = data->pos.posy + 4
		pente = dirY / dirX en regle generale
		si dirX > 0 , le rayon va vers la droite donc on augmente sur x
		si dirX < 0 , le rayon va vers la gauche donc on diminue sur x
	*/
	double	len_rayon;
	double	pente;
	double	x;
	double	y;
	int		xref;  // x actuel qui parcourt la droite du rayon
	int		yref;  // y actuel qui parcourt la droite du rayon
	int		i;  // va permettre de decaler d'une colonne a chaque incrementation jusqu'a croiser un mur si il y en a un

	xref = (int)((data->pos.posx + 4) / data->pos.width);
	yref = (int)((data->pos.posy + 4) / data->pos.height);
	len_rayon = 100000;
	if (dirX > 0)
	{
		pente = dirY / dirX;
		printf("pente = %f -- dirX = %f -- dirY = %f\n", pente, dirX, dirY);
		i = 1;
		while (1)
		{
			y = ((xref + i * data->pos.width) - (data->pos.posx + 4)) * pente;  // y correspond a la valeur en ordonnee (- position du joueur) ou il y a intersection de la droite du rayon avec l'abscisse exacte xref + i * width
			y += (data->pos.posy + 4);
			if (y > 0 && (int)y / data->pos.height < data->pos.ymax && xref + i < data->pos.xmax)  // on verifie si ce y est bien compris entre 0 et ymax
			{
				if (wall_here(data, xref + i, (int)(y / data->pos.height)))  // -> mur cote West (WE)
				{
					//printf("x_wall = %d  --  y_wall = %d\n", xref + i, (int)(y / data->pos.height));
					len_rayon = sqrt(pow((y - (data->pos.posy + 4)), 2) + pow((xref + i * data->pos.width) - (data->pos.posx + 4), 2));
					break;
				}
			}
			else  // cas ou je suis sorti de la map (peut se produire quand la pente est trop inclinee [correspond a un rayon quasi vertical])
				break;
			i++;
		}
		/*i = 1;
		if (dirY > 0)  // on est entre 0 et -PI / 2
		{
			while (1)
			{
				if (pente < 0)
					x = ((yref + i * data->pos.height) - (data->pos.posy + 4)) / (-pente);
				else
					x = ((yref + i * data->pos.height) - (data->pos.posy + 4)) / (pente);
				x += (data->pos.posx + 4);
				if (x > 0 && (int)x / data->pos.width < data->pos.xmax && yref + i < data->pos.ymax)
				{
					if (wall_here(data, (int)x / data->pos.width, yref + i))  // -> mur cote Nord (NO)
					{
						if (sqrt(pow((x - (data->pos.posx + 4)), 2) + pow((yref + i * data->pos.height) - (data->pos.posy + 4), 2)) < len_rayon)
							len_rayon = sqrt(pow((x - (data->pos.posx + 4)), 2) + pow((yref + i * data->pos.height) - (data->pos.posy + 4), 2));
						break;
					}
				}
				else
					break;
				i++;
			}
		}
		else if (dirY < 0)  // on est entre 0 et +PI / 2
		{
			while (1)
			{
				if (pente < 0)
					x = ((yref - i * data->pos.height) - (data->pos.posy + 4)) / (-pente);
				else
					x = ((yref - i * data->pos.height) - (data->pos.posy + 4)) / (pente);
				x += (data->pos.posx + 4);
				if (x > 0 && (int)x / data->pos.width < data->pos.xmax && yref - i >= 0)
				{
					if (wall_here(data, (int)x / data->pos.width, yref - i))  // -> mur cote Sud (SO)
					{
						if (sqrt(pow((x - (data->pos.posx + 4)), 2) + pow((yref - i * data->pos.height) - (data->pos.posy + 4), 2)) < len_rayon)
							len_rayon = sqrt(pow((x - (data->pos.posx + 4)), 2) + pow((yref - i * data->pos.height) - (data->pos.posy + 4), 2));
						break;
					}
				}
				else
					break;
				i++;
			}
		}*/
	}
	else if (dirX < 0)
	{
		pente = dirY / dirX;
		i = 0;
		while (1)
		{
			y = ((xref - i * data->pos.width) - (data->pos.posx + 4)) * pente;
			y += (data->pos.posy + 4);
			if (y > 0 && (int)y / data->pos.height < data->pos.ymax && xref + i < data->pos.xmax)
			{
				if (wall_here(data, xref + i, (int)y / data->pos.height))  // -> mur cote Est (EA)
				{
					len_rayon = sqrt(pow((y - (data->pos.posy + 4)), 2) + pow((xref - i * data->pos.width) - (data->pos.posx + 4), 2));
					break;
				}
			}
			else
				break;
			i++;
		}
		i = 1;
		if (dirY > 0)  // on est entre 0 et -PI / 2
		{
			while (1)
			{
				x = ((yref + i * data->pos.height) - (data->pos.posy + 4)) / pente;
				x += (data->pos.posx + 4);
				if (x > 0 && (int)x / data->pos.width < data->pos.xmax && yref + i < data->pos.ymax)
				{
					if (wall_here(data, (int)x / data->pos.width, yref + i))  // -> mur cote Nord (NO)
					{
						if (sqrt(pow((x - (data->pos.posx + 4)), 2) + pow((yref + i * data->pos.height) - (data->pos.posy + 4), 2)) < len_rayon)
							len_rayon = sqrt(pow((x - (data->pos.posx + 4)), 2) + pow((yref + i * data->pos.height) - (data->pos.posy + 4), 2));
						break;
					}
				}
				else
					break;
				i++;
			}
		}
		else if (dirY < 0)  // on est entre 0 et +PI / 2
		{
			while (1)
			{
				x = ((yref - i * data->pos.height) - (data->pos.posy + 4)) / pente;
				x += (data->pos.posx + 4);
				if (x > 0 && (int)x / data->pos.width < data->pos.xmax && yref - i >= 0)
				{
					if (wall_here(data, (int)x / data->pos.width, yref - i))  // -> mur cote Sud (SO)
					{
						if (sqrt(pow((x - (data->pos.posx + 4)), 2) + pow((yref - i * data->pos.height) - (data->pos.posy + 4), 2)) < len_rayon)
							len_rayon = sqrt(pow((x - (data->pos.posx + 4)), 2) + pow((yref - i * data->pos.height) - (data->pos.posy + 4), 2));
						break;
					}
				}
				else
					break;
				i++;
			}
		}
	}
	else
		len_rayon = 50;
	// dernier cas particulier ou dirX = 0
	return (len_rayon);
}

int	wall_here(t_data *data, int x, int y)
{
	int	xref;

	xref = 0;
	while (data->tab_walls[y][xref] != -1)
	{
		if (data->tab_walls[y][xref] == x)
			return (1);
		xref++;
	}
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
