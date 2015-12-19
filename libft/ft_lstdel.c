/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 12:28:53 by ealbecke          #+#    #+#             */
/*   Updated: 2015/11/16 12:51:31 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*new;

	new = *alst;
	while (new != NULL)
	{
		del((new)->content, (new)->content_size);
		free(new);
		new = new->next;
	}
	*alst = NULL;
}
