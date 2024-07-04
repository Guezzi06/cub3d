/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:00:08 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/17 15:27:28 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

static int	len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	count_nb_chaine(char const *s, char c, int i)
{
	int	nb;

	nb = 0;
	if (!s || s[0] == 0)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb++;
			while (s[i] == c)
				i++;
			i--;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb++;
	return (nb);
}

static char	*ft_strdup_split(char const *src, int size)
{
	int		i;
	char	*chaine;

	i = 0;
	chaine = NULL;
	chaine = malloc(sizeof(char) * (size + 1));
	if (chaine == NULL)
		return (NULL);
	while (i < size)
	{
		chaine[i] = src[i];
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		nb_mots;
	char	**split;

	i = 0;
	nb_mots = count_nb_chaine(s, c, i);
	split = malloc(sizeof(char *) * (nb_mots + 1));
	if (split == NULL)
		return (NULL);
	while (i < nb_mots)
	{
		while (*s && *s == c)
			s++;
		j = len_word(s, c);
		split[i] = ft_strdup_split(s, j);
		s += j;
		i++;
	}
	split[i] = NULL;
	return (split);
}
/*
int main(void)
{
	int i = 0;
	//char a[] = "ais-gvdj-cn  shcbd--ss-GYb4X6hncd-skncdiygU007309_k";
	char **split;
	char *splitme = strdup(" Tripouille");
	//char *splitme = strdup("tripouille ");
	split = ft_split(splitme, ' ');
	//char **split = ft_split(invalidReadCheck, 0);
	while (i < 2)
	{
		printf("%s\n", split[i]);
		i++;
	}
	free(split);
	return (0);
}*/
