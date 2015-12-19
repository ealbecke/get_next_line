/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:32:49 by ealbecke          #+#    #+#             */
/*   Updated: 2015/10/26 12:23:28 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_front_trim(char const *s)
{
	size_t		start;
	char		*str;

	str = NULL;
	str = (char *)s;
	start = 0;
	while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
		start++;
	if (start == ft_strlen(s))
		return (0);
	return (start);
}

static size_t	ft_end_trim(char const *s)
{
	size_t		end;
	char		*str;

	str = (char *)s;
	end = ft_strlen(str) - 1;
	while ((str[end] == ' ' || str[end] == '\t' || str[end] == '\n') &&
			end > 0)
		end--;
	return (end);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		max_len;
	int		min_len;
	int		i;

	if ((char *)s != NULL)
	{
		min_len = ft_front_trim((char *)s);
		max_len = ft_end_trim((char *)s);
		i = max_len - min_len + 1;
		str = ft_strsub(s, min_len, i);
		if (*str == ' ' || *str == '\t' || *str == '\n')
			*str = '\0';
		return (str);
	}
	return (NULL);
}
