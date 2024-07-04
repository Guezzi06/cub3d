/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:27:14 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/15 16:21:26 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;

	if ((!src && !size) || (!dest && !size))
		return (0);
	i = 0;
	d = ft_strlen(dest);
	s = ft_strlen(src);
	if (size == 0)
		return (s);
	if (size - 1 < d)
		return (s + size);
	while (d + i < size - 1 && src[i])
	{
		dest[d + i] = src[i];
		i++;
	}
	dest[d + i] = '\0';
	return (s + d);
}
/*
int main()
{
	size_t s;
	char a[100] = "Anouar ";
	char b[] = "guezzi";
	s = ft_strlcat(a, b, 10);
	printf("%s et %zu", a, s);
}
*/
