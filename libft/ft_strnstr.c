/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:02:31 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/17 15:32:06 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

static char	*boucle(const char *s1, const char *s2, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		if (s2[j] == s1[i])
		{
			while (s2[j] == s1[i] && j < len && i < len && s1[i])
			{
				i++;
				j++;
			}
			if ((j == len || s2[j] == 0) && len != 0
				&& ft_strlen(s1) >= ft_strlen(s2))
			{
				return ((char *)s1 + i - j);
			}
			i -= j;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*ptr;

	if ((!s1 && !len) || (!s2 && !len))
		return (0);
	if (len < ft_strlen(s2) && s1)
		return (0);
	if (s2[0] == 0)
		return ((char *)s1);
	if (len > 1000000000)
		len = ft_strlen(s1);
	ptr = boucle(s1, s2, len);
	return (ptr);
}
/*
int main()
{
	char haystack[30] = "aaabcabcd";
	//char needle[10] = "aabc";
}*/
