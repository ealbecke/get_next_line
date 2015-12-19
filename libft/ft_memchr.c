/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:12:37 by ealbecke          #+#    #+#             */
/*   Updated: 2015/10/26 10:57:37 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	c2;

	if (s == NULL)
		return (NULL);
	i = 0;
	ptr = (unsigned char*)s;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == c2)
			return ((void*)(ptr + i));
		i++;
	}
	return (NULL);
}
