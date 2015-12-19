/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:11:21 by ealbecke          #+#    #+#             */
/*   Updated: 2015/11/16 13:17:01 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_strrev(char *str)
{
	int		x;
	int		y;
	char	z;

	x = -1;
	y = 0;
	x = ft_strlen(str);
	x--;
	while (y < x)
	{
		z = str[x];
		str[x] = str[y];
		str[y] = z;
		y++;
		x--;
	}
}

static void			verif_less(int *n, int *less)
{
	if (*n == -2147483648)
	{
		*less = 2;
		*n += 1;
		*n = -*n;
		*n /= 10;
	}
	else if (*n < 0)
	{
		*less = 1;
		*n = -*n;
	}
}

char				*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		less;

	i = -1;
	less = 0;
	if (n == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	if ((str = ft_strnew(12)) == NULL)
		return (NULL);
	verif_less(&n, &less);
	less == 2 ? str[++i] = '8' : 0;
	while (n > 0)
	{
		str[++i] = n % 10 + 48;
		n /= 10;
	}
	less > 0 ? str[++i] = '-' : 0;
	str[++i] = '\0';
	ft_strrev(str);
	return (str);
}
