/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:03:44 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/22 14:54:10 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	allouer(int n)
{
	int	a;

	a = 1;
	if (n == 0)
		return (2);
	if (n == -2147483648)
		return (12);
	if (n < 0)
	{
		a++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		a++;
	}
	return (a);
}

static void	conditions(char *s, int *n, int *i)
{
	if (*n == 0)
	{
		s[*i] = '0';
		*i += 1;
	}
	else if (*n < 0 && *n != -2147483648)
	{
		s[0] = '-';
		*n *= -1;
	}
	else if (*n == -2147483648)
	{
		s[0] = '-';
		s[10] = 56;
		*n = 214748364;
		*i += 1;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		a;
	char	*s;

	i = 0;
	a = allouer(n);
	s = malloc(a);
	if (s == NULL)
		return (NULL);
	conditions(s, &n, &i);
	while (n > 0)
	{
		s[a - i - 2] = n % 10 + 48;
		n /= 10;
		i++;
	}
	s[a - 1] = '\0';
	return (s);
}
