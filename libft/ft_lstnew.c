/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 12:27:36 by ealbecke          #+#    #+#             */
/*   Updated: 2015/11/16 12:27:48 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*nouveau;

	nouveau = (t_list *)malloc(sizeof(t_list));
	if (!(nouveau))
		return (NULL);
	if (!content)
	{
		nouveau->content = NULL;
		nouveau->content_size = 0;
	}
	else
	{
		nouveau->content = (void*)malloc(content_size);
		if (!nouveau->content)
			return (NULL);
		nouveau->content_size = content_size;
		ft_strncpy(nouveau->content, content, content_size);
	}
	nouveau->next = NULL;
	return (nouveau);
}
