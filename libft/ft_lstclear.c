/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:32:53 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/16 11:17:59 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*save;

	if (lst && del)
	{
		ptr = *lst;
		if (ptr == NULL)
			return ;
		while (ptr != NULL)
		{
			del(ptr->content);
			save = ptr;
			ptr = ptr->next;
			free(save);
		}
		*lst = NULL;
	}
}
