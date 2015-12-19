/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:30:52 by ealbecke          #+#    #+#             */
/*   Updated: 2015/10/22 16:29:30 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(s2);
	i = 0;
	if (s2[i] == '\0' || !s2)
		return ((char*)&s1[i]);
	while ((s1[i] && ((i + size) <= n)))
	{
		if (ft_strncmp(&s1[i], s2, size) == 0)
			return ((char*)&s1[i]);
		else
			i++;
	}
	return (NULL);
}
