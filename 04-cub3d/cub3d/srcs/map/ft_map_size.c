/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:57:16 by msessa            #+#    #+#             */
/*   Updated: 2021/03/26 18:27:28 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static bool	ft_update_map_size(t_map *map, char *line)
{
	char	*o_line;
	int		len;

	o_line = line;
	while (*line && ft_is_map_el(*line))
		line++;
	len = line - o_line;
	if (len == 0 || o_line[len] != '\0')
	{
		ft_error(err_map_grid);
		return (false);
	}
	map->map_size.y++;
	if (len > map->map_size.x)
		map->map_size.x = len;
	return (true);
}

int	ft_init_map_size(int fd, t_map *map, char **line)
{
	int	read_out;
	int	check_p;

	read_out = 1;
	while (read_out > 0)
	{
		check_p = ft_update_map_size(map, *line);
		free(*line);
		if (check_p == false)
			break ;
		read_out = get_next_line(fd, line);
		if (read_out < 0)
			ft_error(err_map_gnl);
	}
	if (read_out >= 0 && check_p == true)
	{
		check_p = ft_update_map_size(map, *line);
		free(*line);
	}
	if (read_out < 0 || check_p == false)
		return (-1);
	return (read_out);
}
