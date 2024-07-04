/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:36:11 by mgayout           #+#    #+#             */
/*   Updated: 2024/07/02 18:12:02 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

char	content_up(t_map *map)
{
	t_map	*tmp;
	int		x;
	int		y;
	
	tmp = map;
	x = map->x;
	y = map->y;
	//printf("x = %d | y = %d\n", x, y);
	if (y == 0)
		return (' ');
	tmp = tmp->prev;
	while (tmp && (tmp->x != x || tmp->y != y - 1))
		tmp = tmp->prev;
	if (!tmp)
		return (' ');
	return (tmp->content);
}

char	content_down(t_data *data, t_map *map)
{
	t_map	*tmp;
	int		x;
	int		y;
	
	tmp = map;
	x = map->x;
	y = map->y;
	//printf("new : x = %d | y = %d\n", x, y);
	if (y == data->pos.ymax + 1)
		return (' ');
	tmp = tmp->next;
	while (tmp && (tmp->x != x || tmp->y != y + 1))
		tmp = tmp->next;
	if (!tmp)
		return (' ');
	//printf("x = %d | y = %d\n", tmp->x, tmp->y);
	//printf("content = %c\n", tmp->content);
	return (tmp->content);
}

int	ft_atoi_color(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - '0');
	}
	//printf("i = %d | strlen = %d\n", i, (int)ft_strlen(str));
	//printf("str[i - 1] = %c | str[i] = %c\n", str[i - 1], str[i]);
	if (str[i] != '\0' && str[i] != '\n')
		return (256);
	return (result * sign);
}
