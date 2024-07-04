/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:16:25 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/19 20:42:15 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_nbr(int n, int *count)
{
	if (n == -2147483648)
		*count += write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar('-', count);
		}
		if (n >= 10)
		{
			ft_printf_nbr(n / 10, count);
			ft_printf_nbr(n % 10, count);
		}
		else
			ft_putchar(n + '0', count);
	}
}
