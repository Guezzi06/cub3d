/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:06:10 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/16 14:00:00 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*tab;
	char	*t;

	i = 0;
	if (size == 0)
		return (ft_strdup(""));
	if (size >= 9223372036854775807 || nmemb >= 9223372036854775807)
		return (NULL);
	tab = malloc(size * nmemb);
	if ((tab == NULL || size == 0 || nmemb == 0) && size * nmemb != 0)
		return (NULL);
	t = tab;
	while (i < size * nmemb)
	{
		t[i] = 0;
		i++;
	}
	return (tab);
}
