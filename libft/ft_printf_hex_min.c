/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_min.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:24:30 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/20 12:42:48 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hex_min(unsigned int n, int *count)
{
	if (n >= 16)
	{
		ft_printf_hex_min(n / 16, count);
		ft_printf_hex_min(n % 16, count);
	}
	else if (n < 10)
		ft_putchar(n + '0', count);
	else
		ft_putchar(n + 'a' - 10, count);
}
