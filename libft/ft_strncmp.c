/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:29:25 by ealbecke          #+#    #+#             */
/*   Updated: 2015/10/22 16:26:46 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 && !s2)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return ((s1 == NULL) ? -1 : 1);
	if (n > ft_strlen(s1) || n > ft_strlen(s2))
		n = (n > ft_strlen(s1)) ? ft_strlen(s1) + 1 : ft_strlen(s2) + 1;
	return (ft_memcmp(s1, s2, n));
}
