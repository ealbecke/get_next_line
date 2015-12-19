/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 16:08:51 by ealbecke          #+#    #+#             */
/*   Updated: 2015/11/16 13:16:06 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		size;
	int		num;

	size = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		size = -1;
		str++;
	}
	if (*str == 0)
		str++;
	num = 0;
	while (*str != '\0' && ft_isdigit(*str))
	{
		num = (*str - '0' + num * 10);
		str++;
	}
	return (num * size);
}
