/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:53:19 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/16 14:53:29 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
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
	ft_bzero(ptr, 14);
	while (i < 14)
	{
		printf("%d ", str[i]);
		i++;
	}
}
*/
