/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:24:45 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/08 15:33:03 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
void	ft_putchar(int c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_printf_ptr(unsigned long long n, int *count);
void	ft_printf_hex_ptr(unsigned long long n, int *count);
void	ft_printf_nbr(int n, int *count);
void	ft_printf_uns_int(unsigned int n, int *count);
void	ft_printf_hex_min(unsigned int n, int *count);
void	ft_printf_hex_maj(unsigned int n, int *count);
void	ft_printf_perc(int *count);

#endif
