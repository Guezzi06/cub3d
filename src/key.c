/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:38:48 by mgayout           #+#    #+#             */
/*   Updated: 2024/07/12 16:03:41 by aguezzi          ###   ########.fr       */
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
	draw(data, data->x, data->y);
	return (0);
}
