/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:44:13 by msessa            #+#    #+#             */
/*   Updated: 2021/03/26 19:28:59 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static void	ft_init_params(bool *params_set)
{
	int	i;

	i = 0;
	while (i < MIN_MAP_PARAMS)
	{
		params_set[i] = false;
		i++;
	}
}

static bool	ft_check_params(bool *params_set)
{
	int	i;

	i = 0;
	while (i < MIN_MAP_PARAMS)
	{
		if (params_set[i] == false)
			return (false);
		i++;
	}
	return (true);
}

static int	ft_set_map(int fd, t_map *map)
{
	char	*line;
	int		read_out;
	bool	params_set[MIN_MAP_PARAMS];

	ft_init_params(params_set);
	read_out = ft_init_map_param(fd, map, &line, params_set);
	// to test
	ft_print_params_set(params_set);
	if (read_out > 0 && !ft_check_params(params_set))
	{
		free(line);
		ft_error(err_map_param_miss);
		read_out = -1;
	}
	if (read_out <= 0)
		return (0);
	read_out = ft_init_map_size(fd, map, &line);
	if (read_out < 0)
		return (0);
	return (1);
}

t_map	*ft_init_map(char *map_path)
{
	t_map	*map;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_error(err_map_path);
		return (0);
	}
	map = ft_alloc_map();
	if (map && !ft_set_map(fd, map))
		map = ft_free_map(map);
	close(fd);
	if (map && !ft_set_map_grid(map, map_path))
		map = ft_free_map(map);
	return (map);
}
