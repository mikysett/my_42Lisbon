/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:22:04 by msessa            #+#    #+#             */
/*   Updated: 2021/03/26 19:31:26 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

t_map_el	**ft_alloc_map_grid(t_size map_size)
{
	t_map_el	**map_grid;
	int			i;

	i = 0;
	map_grid = malloc(sizeof(t_map_el *) * map_size.y);
	if (!map_grid)
		return (0);
	while (i < map_size.y)
	{
		map_grid[i] = malloc(sizeof(t_map_el) * map_size.x);
		if (!map_grid[i])
		{
			while (--i >= 0)
				free(map_grid[i]);
			free(map_grid);
			return (0);
		}
		i++;
	}
	return (map_grid);
}

int	ft_set_map_grid(t_map *map, char *map_path)
{
	int		fd;
	int		read_out;
	char	*line;

	if (map->map_size.x <= 3 || map->map_size.y <= 3)
		return (ft_error(err_map_grid));
	map->map_grid = ft_alloc_map_grid(map->map_size);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (ft_error(err_map_path));
	read_out = get_next_line(fd, &line);
	while (read_out > 0 && !ft_is_map_grid(*line, params_set))
	{

	}

	close(fd);
	return (1);
}