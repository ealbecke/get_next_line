/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:27:43 by ealbecke          #+#    #+#             */
/*   Updated: 2015/10/26 12:14:34 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	new = NULL;
	if (s && f)
	{
		if ((new = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			new[i] = (*f)((char)s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
