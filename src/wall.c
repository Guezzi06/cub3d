/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:16:55 by mgayout           #+#    #+#             */
/*   Updated: 2024/07/03 14:49:19 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

int	init_walls(t_data *data, char *file)
{
	char	*str;
	char	**split_arg;
	int		status;
	int		fd;


	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	status = 0;
	data->parse_status = 1;
	while (status != 6)
	{
		if (valid_str(str))
		{
			split_arg = ft_split(str, ' ');
			status = add_img(data, split_arg, status);
			free_tab(split_arg);
		}
		if (status == -1)
		{
			close(fd);
			return (1);
		}
		free(str);
		str = get_next_line(fd);
		data->parse_status += 1;
	}
	free(str);
	close(fd);
	return (0);
}

int	add_img(t_data *data, char **arg, int status)
{
	if (!ft_strcmp(arg[0], "NO") && !data->img.n_wall)  // il faudrait check a chaque fois si le path est bien valide
		data->img.n_wall = ft_strdup(arg[1]);
	else if (!ft_strcmp(arg[0], "EA") && !data->img.e_wall)
		data->img.e_wall = ft_strdup(arg[1]);
	else if (!ft_strcmp(arg[0], "SO") && !data->img.s_wall)
		data->img.s_wall = ft_strdup(arg[1]);
	else if (!ft_strcmp(arg[0], "WE") && !data->img.w_wall)
		data->img.w_wall = ft_strdup(arg[1]);
	else if (!ft_strcmp(arg[0], "C") && !data->img.c_wall)
		data->img.c_wall = ft_strdup(arg[1]);
	else if (!ft_strcmp(arg[0], "F") && !data->img.f_wall)
		data->img.f_wall = ft_strdup(arg[1]);
	else
		return (-1);
	status += 1;
	return (status);
}

int	valid_str(char *str)
{
	int	i;

	i = 0;
	//if (!str[i])
	//	return (1);  ajouter peut-etre cette condition  
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			return (1);
		i++;
	}
	return (0);	
}