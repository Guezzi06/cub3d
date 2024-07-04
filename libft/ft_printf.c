/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:53:55 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/08 15:35:53 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(const char *format, va_list param, int *count, size_t *i)
{
	*i += 1;
	if (format[*i] == 'c')
		ft_putchar(va_arg(param, int), count);
	else if (format[*i] == 's')
		ft_putstr(va_arg(param, char *), count);
	else if (format[*i] == 'p')
		ft_printf_ptr(va_arg(param, unsigned long long), count);
	else if (format[*i] == 'd' || format[*i] == 'i')
		ft_printf_nbr(va_arg(param, int), count);
	else if (format[*i] == 'u')
		ft_printf_uns_int(va_arg(param, unsigned int), count);
	else if (format[*i] == 'x')
		ft_printf_hex_min(va_arg(param, unsigned int), count);
	else if (format[*i] == 'X')
		ft_printf_hex_maj(va_arg(param, unsigned int), count);
	else if (format[*i] == '%')
		ft_printf_perc(count);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		count;
	va_list	param;

	i = 0;
	count = 0;
	va_start(param, format);
	while (format[i] && i < ft_strlen((const char *)format))
	{
		if (format[i] == '%')
			ft_print(format, param, &count, &i);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	return (count);
}
