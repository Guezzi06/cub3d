/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:33:03 by mgayout           #+#    #+#             */
/*   Updated: 2024/07/03 12:00:56 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	init_map(t_data *data, char *file)
{
	t_map	*map;
	char	*str;
	int		fd;
	int		i;
	int		y;

	map = NULL;
	fd = open(file, O_RDONLY);
	y = 0;
	str = get_next_line(fd);
	while (data->parse_status > 0 || !valid_str(str))
	{
		data->parse_status -= 1;
		free(str);
		str = get_next_line(fd);
	}
	while (str)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '\n')
				break ;
			fill_map(&map, str[i], i, y);
			i++;
		}
		y += 1;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	data->map = map;
}

void	fill_map(t_map **map, char content, int x, int y)
{
	t_map	*new;
	t_map	*last;

	new = malloc(sizeof(t_map) * 1);
	new->content = content;
	new->x = x;
	new->y = y;
	new->prev = NULL;
	new->next = NULL;
	if (!*map)
		*map = new;
	else
	{
		last = last_map(map);
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}

t_map	*last_map(t_map **map)
{
	t_map	*last;

	last = *map;
	while (last->next)
		last = last->next;
	return (last);
}

void	print_map(t_map *map)
{
	int	y;

	y = 0;
	while (map)
	{
		//printf("content = %c | x = %d | y = %d\n", map->content, map->x, map->y);
		if (y < map->y)
		{
			printf("\n");
			y += 1;
		}
		printf("%c", map->content);
		map = map->next;
	}
	printf("\n");
}
