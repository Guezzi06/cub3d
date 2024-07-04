/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:35:21 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/17 15:33:03 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

static char	*boucletrim(char const *s1, char *new, int a, int b)
{
	int	j;

	j = 0;
	while (j < b - a + 1)
	{
		new[j] = (char)s1[a + j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

static int	caractere_trouve(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		b;
	char	*new;

	a = 0;
	if (!s1)
		return (ft_strdup(""));
	while (caractere_trouve(s1[a], set) == 1)
		a++;
	b = ft_strlen(s1) - 1;
	while (caractere_trouve(s1[b], set) == 1)
		b--;
	if (b - a + 2 <= 0)
		return (ft_strdup(""));
	else
		new = malloc(sizeof(char) * (b - a + 2));
	if (!new)
		return (NULL);
	new = boucletrim(s1, new, a, b);
	return (new);
}
/*
int main()
{
	char * s = ft_strtrim("   xxxtripouille", " x");
	printf("%s", s);
}*/
