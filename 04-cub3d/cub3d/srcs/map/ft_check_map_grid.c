/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:37:02 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 17:24:49 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static bool	ft_check_map_cell(t_map_el_type *cell)
{
	if ((cell[d_cn] != empty && cell[d_cn] != wall
			&& (cell[d_l] == empty || cell[d_b] == empty
				|| cell[d_bl] == empty || cell[d_tl] == empty))
		|| (cell[d_cn] == empty
			&& ((cell[d_l] != empty && cell[d_l] != wall)
				|| (cell[d_b] != empty && cell[d_b] != wall)
				|| (cell[d_bl] != empty && cell[d_bl] != wall)
				|| (cell[d_tl] != empty && cell[d_tl] != wall))))
		return (false);
	return (true);
}

static bool	ft_check_map_row(t_map_el **grid, int y, t_size map_size)
{
	t_map_el_type	cell[NB_DIRECTIONS];
	int				x;

	x = 0;
	while (x < map_size.x)
	{
		cell[d_l] = empty;
		cell[d_b] = empty;
		cell[d_bl] = empty;
		cell[d_tl] = empty;
		cell[d_cn] = grid[x][y].type;
		if (x + 1 != map_size.x)
			cell[d_l] = grid[x + 1][y].type;
		if (y + 1 != map_size.y)
			cell[d_b] = grid[x][y + 1].type;
		if (x + 1 != map_size.x && y + 1 != map_size.y)
			cell[d_bl] = grid[x + 1][y + 1].type;
		if (x + 1 != map_size.x && y - 1 >= 0)
			cell[d_tl] = grid[x + 1][y - 1].type;
		if (!ft_check_map_cell(cell))
			return (false);
		x++;
	}
	return (true);
}

bool	ft_check_map_grid(t_map_el **grid, t_size map_size)
{
	int	y;

	y = 0;
	while (y < map_size.y)
	{
		if (!ft_check_map_row(grid, y, map_size))
			return (false);
		y++;
	}
	return (true);
}
