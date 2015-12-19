/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:12:18 by ealbecke          #+#    #+#             */
/*   Updated: 2015/10/22 15:44:47 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dst_;
	const char		*src_;

	dst_ = dst;
	src_ = src;
	while (n > 0)
	{
		if (*src_ == (char)c)
		{
			*dst_++ = *src_++;
			return ((void*)dst_);
		}
		*dst_++ = *src_++;
		n--;
	}
	return (NULL);
}
