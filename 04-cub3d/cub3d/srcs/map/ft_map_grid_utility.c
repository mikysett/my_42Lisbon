/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid_utility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:41:10 by msessa            #+#    #+#             */
/*   Updated: 2021/03/29 20:32:20 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_set_grid_line(t_map_el *grid_line, int grid_size)
{
	int	i;

	i = 0;
	while (i < grid_size)
	{
		grid_line->extra = 0;
		grid_line->type = empty;
		grid_line++;
		i++;
	}
}

t_map_el_type	ft_get_el_type(char c)
{
	if (c == ' ')
		return (empty);
	else if (c == '0')
		return (e_floor);
	else if (c == '1')
		return (wall);
	else if (c == '2')
		return (item);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (player);
	else
		return (invalid);
}

t_map_el	**ft_alloc_map_grid(t_size map_size)
{
	t_map_el	**map_grid;
	int			i;

	i = 0;
	map_grid = malloc(sizeof(t_map_el *) * map_size.x);
	if (!map_grid)
		return (0);
	while (i < map_size.x)
	{
		map_grid[i] = malloc(sizeof(t_map_el) * map_size.y);
		if (!map_grid[i])
		{
			while (--i >= 0)
				free(map_grid[i]);
			free(map_grid);
			return (0);
		}
		ft_set_grid_line(map_grid[i], map_size.y);
		i++;
	}
	return (map_grid);
}
