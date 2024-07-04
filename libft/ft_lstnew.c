/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:57:01 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/15 14:05:51 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nouveau;

	nouveau = malloc(sizeof(*nouveau));
	if (nouveau == NULL)
		return (NULL);
	nouveau->next = NULL;
	nouveau->content = content;
	return (nouveau);
}
