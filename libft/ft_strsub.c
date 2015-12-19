/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:32:30 by ealbecke          #+#    #+#             */
/*   Updated: 2015/12/04 14:11:29 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*new;
	unsigned int	i;

	if (!(new = ft_strnew(len + 1)))
		return (NULL);
	if (s == NULL)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (i < len)
	{
		new[i] = str[start];
		start++;
		i++;
	}
	return (new);
}
