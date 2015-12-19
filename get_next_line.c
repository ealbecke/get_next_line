/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:51:07 by ealbecke          #+#    #+#             */
/*   Updated: 2015/12/17 21:46:28 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_put_buffer_in_line(char **stat, char **line, char *buffer, int i)
{
	char	*tmp;

	tmp = NULL;
	if (*stat != NULL)
	{
		if (!(*line = ft_strnew(ft_strlen(*stat) + 1)))
			return (-1);
		ft_strcpy(*line, *stat);
		*line = ft_strjoin(*line, ft_strsub(buffer, 0, i));
	}
	else if (*stat == NULL)
	{
		if (!(*line = ft_strnew(i + 1)))
			return (-1);
		*line = ft_strsub(buffer, 0, i);
	}
	tmp = ft_strsub(buffer, i + 1, BUFF_SIZE - i);
	*stat = NULL;
	if (!(*stat = ft_strnew(ft_strlen(tmp) + 1)))
		return (-1);
	*stat = ft_strcpy(*stat, tmp);
	return (1);
}

int			ft_put_in_line(int i, char **stat, char **line)
{
	char	*tmp;

	tmp = NULL;
	*line = ft_strsub(*stat, 0, i);
	tmp = ft_strsub(*stat, i + 1, (ft_strlen(*stat) - i));
	*stat = NULL;
	if (!(*stat = ft_strnew(ft_strlen(tmp) + 1)))
		return (-1);
	*stat = ft_strcpy(*stat, tmp);
	return (1);
}

char		*ft_put_in_stat(char **stat, char **buffer, int i, char **line)
{
	char	*tmp;

	tmp = NULL;
	if (i == -2)
	{
		if (!(*line = ft_strnew(BUFF_SIZE + 1)))
			return (NULL);
		if (*stat)
			*line = ft_strcpy(*line, *stat);
		*line = ft_strcat(*line, *buffer);
		if (**buffer == '\0' && !**line)
			return (NULL);
		*stat = NULL;
		free(*stat);
		return (*line);
	}
	if (!(tmp = ft_strnew(ft_strlen(*buffer) + 1)))
		return (NULL);
	ft_strcpy(tmp, *buffer);
	free(*buffer);
	if (!(*buffer = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	if (*stat == NULL)
		return (ft_strsub(tmp, 0, BUFF_SIZE));
	else if (*stat != NULL)
		return (ft_strjoin(*stat, tmp));
	return (0);
}

int			ft_count_n(char *buffer)
{
	int		i;
	int		len;

	i = 0;
	if (buffer == NULL)
		return (-1);
	len = ft_strlen(buffer);
	while (i != len)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	static char		*stat = NULL;
	char			*buffer;
	int				i;

	buffer = NULL;
	i = 0;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if ((i = ft_count_n(stat)) >= 0)
		return (ft_put_in_line(i, &stat, line));
	else
	{
		if (!(buffer = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		while ((i = read(fd, buffer, BUFF_SIZE)) >= 0)
		{
			if ((buffer[i + 1] == '\0') && (ft_count_n(buffer) == -1) && i < BUFF_SIZE)
				return (ft_put_in_stat(&stat, &buffer, -2, line) ? 1 : 0);
			if ((i = ft_count_n(buffer)) >= 0)
				return (ft_put_buffer_in_line(&stat, line, buffer, i));
			else
				stat = ft_put_in_stat(&stat, &buffer, 0, line);
		}
	}
	return (0);
}
