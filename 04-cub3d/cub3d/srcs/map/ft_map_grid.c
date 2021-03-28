/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:22:04 by msessa            #+#    #+#             */
/*   Updated: 2021/03/28 19:02:53 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_get_map_el(char *line, t_map *map, int y, int x)
{
	map->map_grid[y][x].extra = 0;
	map->map_grid[y][x].type = ft_get_el_type(*line);
	if (map->map_grid[y][x].type == player)
	{
		// direction to be improved
		map->player.direction = *line;
		map->player.position = (t_size){x, y};
		map->player.life = 100;
	}
}

int	ft_init_grid_line(char *line, t_map *map, int y, int player_set)
{
	int		x;

	x = 0;
	while (*line)
	{
		ft_get_map_el(line, map, y, x);
		line = ft_next_map_el(line);
		if (map->map_grid[y][x].type == invalid
			|| (player_set == 2 && map->map_grid[y][x].type == player))
			return (0);
		if (map->map_grid[y][x].type == player)
			player_set = 2;
		x++;
	}
	return (player_set);
}

bool	ft_init_map_grid(t_list *map_line, t_map *map)
{
	int		is_ok;
	int		y;

	is_ok = 1;
	y = 0;
	while (map_line)
	{
		is_ok = ft_init_grid_line(map_line->content, map, y, is_ok);
		if (!is_ok)
			return (false);
		map_line = map_line->next;
		y++;
	}
	if (is_ok == 1)
		return (false);
	return (true);
}

// int	ft_set_hash(bool **hash, int x, int y)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (i < y)
// 	{
// 		j = 0;
// 		while (j < x)
// 		{
// 			hash[i][j] = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// bool	**ft_init_grid_hash(t_size map_size)
// {
// 	bool	**grid_hash;
// 	int		i;

// 	i = 0;
// 	grid_hash = malloc(sizeof(bool *) * map_size.y);
// 	if (!grid_hash)
// 		return (0);
// 	while (i < map_size.y)
// 	{
// 		grid_hash[i] = malloc(sizeof(bool) * map_size.x);
// 		if (!grid_hash[i])
// 		{
// 			while (--i >= 0)
// 				free(grid_hash[i]);
// 			free(grid_hash);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	ft_set_hash(grid_hash, map_size.y, map_size.x);
// 	return (grid_hash);
// }

// bool ft_valid_map_grid(t_map *map, bool **grid_hash, int y, int x)
// {
// 	t_map_el_type	cur_type;

// 	cur_type = map->map_grid[y][x].type;
// 	if (grid_hash[y][x])
// 		return (true);
// 	if ((y == 0 || x == 0
// 		|| y == map->map_size.y - 1 || x == map->map_size.x - 1)
// 	{

// 	}
// 		&& (cur_type != empty && cur_type != wall))
// 		return (false);
// 	if (cur_type != empty && cur_type != wall)
// 	{
// 		if (map->map_grid[y - 1][x - 1].type == empty
// 			|| map->map_grid[y - 1][x].type == empty
// 			|| map->map_grid[y - 1][x + 1].type == empty
// 			|| map->map_grid[y][x + 1].type == empty
// 			|| map->map_grid[y + 1][x + 1].type == empty
// 			|| map->map_grid[y + 1][x].type == empty
// 			|| map->map_grid[y + 1][x - 1].type == empty)
// 			return (false);
// 	}
// }

// bool	ft_check_map_grid(t_map *map)
// {
// 	bool	**grid_hash;
// 	bool	map_check;

// 	grid_hash = ft_init_alloc_hash(map);
// 	if (!grid_hash)
// 		return (false);
// 	map_check = ft_valid_map_grid(map, grid_hash, 0, 0);
// 	ft_free_matrix(grid_hash, map->map_size.y);
// 	return (map_check);
// }

bool	ft_set_map_grid(t_list *map_line, t_map *map)
{
	if (map->map_size.x < 3 || map->map_size.y < 3)
	{
		ft_error(err_map_grid);
		return (false);
	}
	map->map_grid = ft_alloc_map_grid(map->map_size);
	if (!map->map_grid)
	{
		ft_error(err_map_grid);
		return (false);
	}
	while (map_line && !ft_is_map_grid(map_line->content, 0))
		map_line = map_line->next;
	if (!ft_init_map_grid(map_line, map)
		|| !ft_check_map_grid(map->map_grid, map->map_size))
	{
		ft_error(err_map_grid);
		return (false);
	}
	return (true);
}
