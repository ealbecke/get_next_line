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
	free(*stat);
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
	free(*stat);
	*stat = NULL;
	if (!(*stat = ft_strnew(ft_strlen(tmp) + 1)))
		return (-1);
	*stat = ft_strcpy(*stat, tmp);
	return (1);
}

char		*ft_put_in_stat(char **s, char **buffer, int i, char **line)
{
	char	*tp;

	tp = NULL;
	if (i == -2)
	{
		if (!(*line = ft_strnew(BUFF_SIZE + 1)))
			return (NULL);
		if (*s)
			*line = ft_strcpy(*line, *s);
		*line = ft_strcat(*line, *buffer);
		if (**buffer == '\0' && !**line)
			return (NULL);
		free(*s);
		*s = NULL;
		return (*line);
	}
	if (!(tp = ft_strnew(ft_strlen(*buffer) + 1)))
		return (NULL);
	ft_strcpy(tp, *buffer);
	free(*buffer);
	if (!(*buffer = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	if (*s == NULL || *s != NULL)
		return (*s == NULL ? ft_strsub(tp, 0, BUFF_SIZE) : ft_strjoin(*s, tp));
	return (NULL);
}

int			f_count_n(char *buffer)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
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
	char			*buf;
	int				i;

	buf = NULL;
	i = 0;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if ((i = f_count_n(stat)) >= 0)
		return (ft_put_in_line(i, &stat, line));
	else
	{
		if (!(buf = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		while ((i = read(fd, buf, BUFF_SIZE)) >= 0)
		{
			if ((buf[i + 1] == '\0') && (f_count_n(buf) == -1) && i < BUFF_SIZE)
				return (ft_put_in_stat(&stat, &buf, -2, line) ? 1 : 0);
			if ((i = f_count_n(buf)) >= 0)
				return (ft_put_buffer_in_line(&stat, line, buf, i));
			else
				stat = ft_put_in_stat(&stat, &buf, 0, line);
		}
	}
	return ((i < 0) ? -1 : 0);
}
