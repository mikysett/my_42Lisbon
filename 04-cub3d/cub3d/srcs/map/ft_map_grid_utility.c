/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid_utility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:41:10 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 19:05:17 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

t_map_par	*ft_get_map_param(t_list **params, t_map_p_types type_sel)
{
	t_list	*head;

	head = *params;
	while (head)
	{
		if (((t_map_par *)(head->content))->type == type_sel)
			return ((t_map_par *)(head->content));
		head = head->next;
	}
	return (0);
}

void	ft_set_grid_line(t_map_el *grid_line, int grid_size)
{
	int	i;

	i = 0;
	while (i < grid_size)
	{
		grid_line->type = empty;
		grid_line++;
		i++;
	}
}

t_map_el_type	ft_get_el_type(t_map *map, char c)
{
	if (c == ' ')
		return (empty);
	else if (c == '0')
		return (e_floor);
	else if (c == '1')
		return (wall);
	else if (c == '2')
		return (item);
	else if (c == '3' && ft_get_map_param(map->map_params, heal_tex))
		return (heal);
	else if (c == '4' && ft_get_map_param(map->map_params, trap_tex))
		return (trap);
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
