/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 05:54:47 by acase             #+#    #+#             */
/*   Updated: 2020/11/08 16:08:46 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		gnl_fill(char **line, char **buf, char *var_strchr)
{
	char *res;

	if (var_strchr != NULL)
	{
		*line = ft_strndup(*buf, var_strchr - *buf);
		res = ft_strndup(var_strchr + 1, ft_strlen(var_strchr));
		free(*buf);
		*buf = res;
		return (1);
	}
	if (*buf != NULL)
	{
		*line = *buf;
		*buf = NULL;
	}
	else
	{
		*line = ft_strndup("", 1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*buffer[1000];
	int				var_read;
	char			*var_strchr;
	char			*res;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char*)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((var_strchr = ft_strchr(buffer[fd], '\n')) == 0 &&
	(var_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[var_read] = 0;
		if (buffer[fd] == NULL)
			res = ft_strndup(buf, var_read);
		else
		{
			res = ft_strjoin(buffer[fd], buf);
			free(buffer[fd]);
		}
		buffer[fd] = res;
	}
	free(buf);
	return ((var_read == -1) ? -1 : gnl_fill(line, &buffer[fd], var_strchr));
}
