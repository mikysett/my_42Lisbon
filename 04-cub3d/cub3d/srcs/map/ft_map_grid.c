/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:22:04 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 19:05:21 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_set_player_dir(t_player *player, char dir)
{
	if (dir == 'E')
		player->dir = 0;
	else if (dir == 'N')
		player->dir = DEG_90;
	else if (dir == 'W')
		player->dir = DEG_180;
	else if (dir == 'S')
		player->dir = DEG_270;
}

void	ft_get_map_el(char *line, t_map *map, int x, int y)
{
	map->map_grid[x][y].type = ft_get_el_type(map, *line);
	if (map->map_grid[x][y].type == player)
	{
		ft_set_player_dir(&(map->player), *line);
		map->player.pos = (t_size){.x = x, .y = y};
		map->player.cell_pos = (t_size){.x = NB_CELL_POS / 2,
			.y = NB_CELL_POS / 2};
		map->player.life = 100;
	}
}

int	ft_init_grid_line(char *line, t_map *map, int y, int player_set)
{
	int		x;

	x = 0;
	while (*line)
	{
		ft_get_map_el(line, map, x, y);
		line = ft_next_map_el(line);
		if (map->map_grid[x][y].type == invalid
			|| (player_set == 2 && map->map_grid[x][y].type == player))
			return (0);
		if (map->map_grid[x][y].type == player)
		{
			player_set = 2;
			map->map_grid[x][y].type = e_floor;
		}
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
