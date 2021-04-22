/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mm_print_utility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:05:27 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 17:28:05 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

int	ft_set_cell_y(t_mini_map *mm, int y)
{
	if (y == 0)
		return (mm->cell_size - mm->cell_offset.y);
	if (y == mm->nb_cells.y - 1)
		return (mm->cell_offset.y);
	return (mm->cell_size);
}

int	ft_set_cell_x(t_mini_map *mm, int x)
{
	if (x == 0)
		return (mm->cell_size - mm->cell_offset.x);
	if (x == mm->nb_cells.x - 1)
		return (mm->cell_offset.x);
	return (mm->cell_size);
}

t_size	ft_take_dir_point(double dir)
{
	t_size	dir_point;

	dir_point.x = cos(dir) * DIR_DISTANCE;
	dir_point.y = sin(dir) * DIR_DISTANCE;
	return (dir_point);
}
