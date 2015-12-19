/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:03:22 by ealbecke          #+#    #+#             */
/*   Updated: 2015/12/04 15:14:01 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*new;
	t_list	*origin;
	t_list	*prev;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new = f(lst);
	origin = new;
	prev = new;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		prev->next = new;
		prev = new;
		lst = lst->next;
	}
	new->next = NULL;
	return (origin);
}
