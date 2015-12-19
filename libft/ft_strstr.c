/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:32:08 by ealbecke          #+#    #+#             */
/*   Updated: 2015/10/22 16:28:40 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (!s1 || !s2 || (!*s1 && *s2))
		return (NULL);
	if (ft_strlen(s1) == 0)
		return ((char*)s1);
	if (!s2)
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		if (ft_strncmp(&s1[i], s2, ft_strlen(s2)) == 0)
			return ((char*)&s1[i]);
		i++;
	}
	return (NULL);
}
