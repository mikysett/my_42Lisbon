/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:44:13 by msessa            #+#    #+#             */
/*   Updated: 2021/03/25 16:26:40 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_free_map(t_map *map)
{
	// free the params

	// free map grid

	free(map);
}

static int	ft_save_map_param(t_map *map, char *line, int nb_map_params)
{

	return (nb_map_params);
}

static int	ft_update_map_size(t_map *map, char *line, int nb_map_params)
{

	return (nb_map_params);
}

static int	ft_set_map(int fd, t_map *map)
{
	char	*line;
	int		read_out;
	int		nb_map_params;

	nb_map_params = 0;
	read_out = get_next_line(fd, &line);
	while (read_out > 0)
	{
		if (nb_map_params < MIN_MAP_PARAMS)
			nb_map_params = ft_save_map_param(map, line, nb_map_params);
		else
			nb_map_params = ft_update_map_size(map, line, nb_map_params);
		free(line);
		if (nb_map_params < 0)
			break ;
		read_out = get_next_line(fd, &line);
	}
	if (read_out < 0)
		return (ft_error(err_map_gnl));
	else if (nb_map_params < 0)
		return (0);
	return (1);
}

static int	ft_alloc_map(t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (!*map)
		return (ft_error(err_map_malloc));
	(*map)->map_params = 0;
	(*map)->map_grid = 0;
	(*map)->map_size.x = 0;
	(*map)->map_size.y = 0;
	return (1);
}

t_map	*ft_init_map(char *map_path)
{
	t_map		*map;
	int			fd;
	t_errors	err;
	
	err = err_none;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_error(err_map_path);
		return (0);
	}
	if (!ft_alloc_map(&map))
	{
		close(fd);
		return (0);
	}
	if (!ft_set_map(fd, map))
	{
		close(fd);
		ft_free_map(map);
		return (0);
	}
	return (map);
}