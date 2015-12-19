/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:27:05 by ealbecke          #+#    #+#             */
/*   Updated: 2015/11/16 13:32:24 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	if (len_src < size - len_dst)
	{
		ft_memcpy(dst + len_dst, src, len_src);
		dst += len_dst + len_src;
	}
	else
	{
		ft_memcpy(dst + len_dst, src, size - len_dst - 1);
		dst += size - 1;
	}
	*dst = '\0';
	return (len_src + len_dst);
}
