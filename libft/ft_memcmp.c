/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:12:57 by ealbecke          #+#    #+#             */
/*   Updated: 2015/10/22 15:49:44 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_;
	unsigned char	*s2_;

	s1_ = (void *)s1;
	s2_ = (void *)s2;
	if (!s1_ || !s2_)
		return (0);
	while (n--)
	{
		if (*s1_ != *s2_)
			return ((unsigned char)*s1_ - (unsigned char)*s2_);
		s1_++;
		s2_++;
	}
	return (0);
}
