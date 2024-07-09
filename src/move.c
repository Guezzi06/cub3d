/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:54:21 by aguezzi           #+#    #+#             */
/*   Updated: 2024/07/06 15:37:19 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	move_w(t_data *data)
{
	data->x = cos(data->pos.rot) * 5;
	data->y = -sin(data->pos.rot) * 5;
}

void	move_a(t_data *data)
{
	data->x = cos(data->pos.rot + PI / 2) * 5;
	data->y = -sin(data->pos.rot + PI / 2) * 5;
}

void	move_d(t_data *data)
{
	data->x = cos(data->pos.rot - PI / 2) * 5;
	data->y = -sin(data->pos.rot - PI / 2) * 5;
}

void	move_s(t_data *data)
{
	data->x = -cos(data->pos.rot) * 5;
	data->y = sin(data->pos.rot) * 5;
}