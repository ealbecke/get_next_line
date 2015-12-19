/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 12:39:51 by ealbecke          #+#    #+#             */
/*   Updated: 2015/12/04 14:25:20 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c)
			{
				if (s[i] == '\0')
					return (j);
				i++;
			}
		}
		i++;
	}
	return (j);
}

static int		len_words(const char *s, int i, int j, char c)
{
	while (s[i] != c && s[i])
	{
		i++;
		j++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**tbl;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	tbl = (char**)malloc(sizeof(char*) * words + 1);
	if (tbl == NULL)
		return (NULL);
	i = 0;
	j = 0;
	tbl[words] = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		tbl[j] = ft_strsub(s, i, len_words(s, i, 0, c));
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	return (tbl);
}
