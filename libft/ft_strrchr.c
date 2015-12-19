/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:31:08 by ealbecke          #+#    #+#             */
/*   Updated: 2015/10/26 12:43:11 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*str;
	size_t		len;

	str = (char*)s;
	len = ft_strlen(str);
	while (len > 0 && str[len] != (char)c)
		len--;
	if (str[len] == (char)c)
		return (&str[len]);
	return (NULL);
}
