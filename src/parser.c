/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:19:07 by mgayout           #+#    #+#             */
/*   Updated: 2024/07/04 11:49:04 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

int	parse_map(t_data *data)
{
	if (!valid_char(data))
	{
		printf("Error\nInvalid char\n");
		return (1);
	}
	if (!valid_color(data->img.c_wall) || !valid_color(data->img.f_wall))
	{
		printf("Error\nInvalid color\n");
		return (1);
	}
	if (!closed_map(data))
	{
		printf("Error\nInvalid map\n");
		return (1);
	}
	return (0);
}

int	valid_char(t_data *data)
{
	t_map	*tmp;

	tmp = data->map;
	while (tmp)
	{
		if (!ft_strchr("10 PWENS", tmp->content))
		{
			//printf("content = %c\n", tmp->content);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	valid_color(char *str)
{
	char	**arg;
	int		i;
	
	arg = ft_split(str, ',');
	i = 0;
	while (arg[i])
	{
		if (ft_atoi_color(arg[i]) > 255)
		{
			free_tab(arg);
			return (0);
		}
		i++;
	}
	free_tab(arg);
	return (1);
}

int	closed_map(t_data *data)
{
	t_map	*new;
	t_map	*tmp;
	int		status;

	new = new_map(data);
	tmp = new;
	status = 1;
	while (tmp)
	{
		if (tmp->content == ' ')
		{
			if ((tmp->prev && tmp->prev->content == '0') || (tmp->next && tmp->next->content == '0')
			|| content_up(tmp) == '0' || content_down(data, tmp) == '0')
			{
				//printf("x = %d | y = %d\n", tmp->x, tmp->y);
				//if (tmp->prev)
					//printf("prev content = %c\n", tmp->prev->content);
				//if (tmp->next)
					//printf("next content = %c\n", tmp->next->content);
				//printf("up content = %c\n", content_up(tmp));
				//printf("down content = %c\n", content_down(data, tmp));
				status = 0;
				break ;
			}
		}
		tmp = tmp->next;
	}
	free_map(&new);
	//printf("status = %d\n", status);
	return (status);
}

t_map	*new_map(t_data *data)
{
	t_map	*new;
	t_map	*tmp;
	int		i;
	
	new = NULL;
	tmp = data->map;
	i = 0;
	while (i != data->pos.xmax + 3)
	{
		if (i == data->pos.xmax + 2)
			fill_map(&new, ' ', 0, 1);
		else
			fill_map(&new, ' ', i, 0);
		i++;
	}
	i = 1;
	while (tmp)
	{
		fill_map(&new, tmp->content, tmp->x + 1, tmp->y + 1);
		if (tmp->x == (data->pos.xmax - 1))
		{
			fill_map(&new, ' ', data->pos.xmax + 1, i);
			fill_map(&new, ' ', 0, i + 1);
			i++;
		}
		tmp = tmp->next;
	}
	i = 0;
	while (i != data->pos.xmax + 1)
	{
		fill_map(&new, ' ', i + 1, data->pos.ymax + 1);
		i++;
	}
	//print_map(new);
	return (new);
}
