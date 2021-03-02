/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:25:06 by msessa            #+#    #+#             */
/*   Updated: 2021/03/02 16:08:40 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_partial_len(char *buf)
{
	char *o_buf;

	o_buf = buf;
	while (*buf && *buf != '\n')
		buf++;
	return (buf - o_buf);
}

static char	*ft_update_line(char *buf, char *line)
{
	size_t	buf_chunk;
	char	*bigger_line;
	size_t	line_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	buf_chunk = ft_partial_len(buf);
	line_len = *line ? ft_strlen(line) : 0;
	bigger_line = malloc(sizeof(char) * (line_len + buf_chunk + 1));
	if (!bigger_line)
		return (0);
	while (i < line_len)
	{
		bigger_line[i] = line[i];
		i++;
	}
	free(line);
	while (j < buf_chunk)
		bigger_line[i + j++] = *buf++;
	bigger_line[i + j] = '\0';
	return (bigger_line);
}

static int	ft_update_buf(char *buf)
{
	size_t	buf_chunk;
	size_t	i;
	size_t	j;

	buf_chunk = ft_partial_len(buf);
	if (!buf[buf_chunk])
	{
		*buf = '\0';
		return (0);
	}
	i = buf_chunk + 1;
	j = 0;
	while (buf[i])
		buf[j++] = buf[i++];
	buf[j] = '\0';
	return (1);
}

static int	ft_free_exit(char **line)
{
	free(*line);
	*line = 0;
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1] = { '\0' };
	int			read_out;

	if (!line)
		return (-1);
	*line = malloc(sizeof(char) * 1);
	**line = '\0';
	while (1)
	{
		if (*buf != '\0')
		{
			if (!((*line = ft_update_line(buf, *line))))
				return (-1);
			if (ft_update_buf(buf))
				return (1);
		}
		read_out = read(fd, buf, BUFFER_SIZE);
		if (read_out < 0)
			return (ft_free_exit(line));
		else if (read_out == 0)
			return (0);
		buf[read_out] = '\0';
	}
}
