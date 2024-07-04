/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:00:07 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/15 14:04:27 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*debut;
	t_list	*new;

	debut = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			while (debut)
			{
				new = debut->next;
				del(debut->content);
				free(debut);
				debut = new;
			}
		}
		ft_lstadd_back(&debut, new);
		lst = lst->next;
	}
	return (debut);
}
