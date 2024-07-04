/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:51:19 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/16 14:51:36 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
/*
int main()
{
	void *ptr;
	char *str;
	int i = 0;

	ptr = NULL;
	ptr = malloc(sizeof(char) * 18);
	str = ptr;
	if (ptr == NULL)
		return (0);
	ft_memset(ptr, 12, 14);
	while (i < 14)
	{
		printf("%d ", str[i]);
		i++;
	}
}
*/
