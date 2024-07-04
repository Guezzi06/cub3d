/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:58:12 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/19 20:03:10 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hex_ptr(unsigned long long n, int *count)
{
	if (n >= 16)
	{
		ft_printf_hex_ptr(n / 16, count);
		ft_printf_hex_ptr(n % 16, count);
	}
	else if (n < 10)
		ft_putchar(n + '0', count);
	else
		ft_putchar(n + 'a' - 10, count);
}
