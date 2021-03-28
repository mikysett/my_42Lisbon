/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:33:57 by msessa            #+#    #+#             */
/*   Updated: 2021/03/27 19:42:57 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static bool	ft_save_new_line(t_list	**lines, char *line)
{
	t_list	*new_line;

	new_line = ft_lstnew(line);
	if (!new_line)
	{
		ft_free_map_file(lines);
		return (false);
	}
	ft_lstadd_back(lines, new_line);
	return (true);
}

static t_list	**ft_save_map_lines(int fd)
{
	int		read_out;
	char	*line;
	t_list	**lines;

	lines = malloc(sizeof(t_list *));
	if (!lines)
		return (0);
	*lines = 0;
	read_out = get_next_line(fd, &line);
	while (read_out >= 0)
	{
		if (!ft_save_new_line(lines, line))
			return (0);
		if (read_out == 0)
			return (lines);
		read_out = get_next_line(fd, &line);
	}
	if (read_out == -1)
	{
		ft_free_map_file(lines);
		return (0);
	}
	return (lines);
}

t_list	**ft_save_file(char *map_path)
{
	t_list	**map_lines;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_error(err_map_path);
		return (0);
	}
	map_lines = ft_save_map_lines(fd);
	close(fd);
	if (!map_lines)
	{
		ft_error(err_map_gnl);
		return (0);
	}
	return (map_lines);
}
