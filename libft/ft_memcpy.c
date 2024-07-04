/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:58:15 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/16 15:05:55 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	if (!dest && !src && n)
		return (NULL);
	i = 0;
	s = src;
	d = dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int main()
{
	void *ptr = NULL;
	void *ptr2 = NULL;
	char *src;
	char *dest;
	int i = 0;
	int j = 0;

	ptr = malloc(sizeof(char) * 18);
	ptr2 = malloc(sizeof(char) * 18);
	src = ptr;
	dest = ptr2;
	if (ptr == NULL || ptr2 == NULL)
		return (0);
	while (j < 14)
	{
		src[j] = 'a' + j;
		j++;
	}
	ft_memcpy(ptr2, ptr, 14);
	while (i < 14)
	{
		printf("%d ", dest[i]);
		i++;
	}
}*/
