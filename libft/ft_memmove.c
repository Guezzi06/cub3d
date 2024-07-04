/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:43:38 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/15 14:08:44 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = dest;
	s = (char *)src;
	if (d > s)
	{
		while (i < n)
		{
			d[n - i - 1] = s[n - i - 1];
			i++;
		}
	}
	else if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
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
	ptr2 = ptr + 4;
	src = ptr;
	dest = ptr2;
	if (ptr == NULL || ptr2 == NULL)
		return (0);
	while (j < 14)
	{
		src[j] = 'a' + j;
		j++;
	}
	ft_memmove(ptr2, ptr, 14);
	while (i < 14)
	{
		printf("%c ", src[i]);
		i++;
	}
}
*/
