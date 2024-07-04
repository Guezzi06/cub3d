/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:52:20 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/16 14:52:27 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *n)
{
	int		i;
	int		sign;
	int		nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (n[i] == ' ' || n[i] == '\n' || n[i] == '\f' || n[i] == '\v'
		|| n[i] == '\t' || n[i] == '\r')
	{
		i++;
	}
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			sign *= -1;
		i++;
	}
	while (n[i] >= '0' && n[i] <= '9')
	{
		nbr = nbr * 10 + n[i] - 48;
		i++;
	}
	return (nbr * sign);
}
/*
int main(void)
{
	char a[] = "+42lyon";
	printf("%d\n", ft_atoi(a));
}*/
