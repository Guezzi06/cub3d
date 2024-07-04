/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:43:35 by aguezzi           #+#    #+#             */
/*   Updated: 2023/06/07 22:46:15 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_in_file(int fd, char *str, char *buffer)
{
	int	octets_lus;

	if (str == NULL)
		str = ft_calloc(1, 1);
	if (str == NULL)
		return (NULL);
	octets_lus = 1;
	while (octets_lus >= 1)
	{
		octets_lus = read(fd, buffer, BUFFER_SIZE);
		if (octets_lus == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[octets_lus] = '\0';
		str = ft_strjoin_gnl(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*create_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = ft_calloc(i + 2, 1);
	else
		line = ft_calloc(i + 1, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = str[i];
	if (str[i] == '\n')
		line[i + 1] = '\0';
	return (line);
}

char	*next_line(char *str)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	next = NULL;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n' && str[i + 1] != '\0')
		next = ft_calloc(ft_strlen(str) - i, 1);
	if (!next)
	{
		free(str);
		return (NULL);
	}
	while (str[i])
	{
		i++;
		next[j] = str[i];
		j++;
	}
	free(str);
	return (next);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (buffer == NULL)
		return (NULL);
	str = read_in_file(fd, str, buffer);
	if (!str || str[0] == 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = create_line(str);
	str = next_line(str);
	return (line);
}
