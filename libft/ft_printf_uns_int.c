/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:23:08 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/23 14:50:31 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_uns_int(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_printf_nbr(n / 10, count);
		ft_printf_nbr(n % 10, count);
	}
	else
		ft_putchar(n + '0', count);
}
