/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:57:16 by msessa            #+#    #+#             */
/*   Updated: 2021/03/28 19:08:50 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static bool	ft_update_map_size(t_map *map, char *line)
{
	int	nb_el;

	nb_el = 0;
	while (*line)
	{
		line = ft_next_map_el(line);
		if (!line)
			return (false);
		nb_el++;
	}
	map->map_size.y++;
	if (nb_el > map->map_size.x)
		map->map_size.x = nb_el;
	return (true);
}

bool	ft_init_map_size(t_list *map_line, t_map *map)
{
	while (map_line && !ft_is_map_grid(map_line->content, 0))
		map_line = map_line->next;
	if (!map_line)
		return (false);
	while (map_line)
	{
		if (!ft_update_map_size(map, map_line->content))
			return (false);
		map_line = map_line->next;
	}
	return (true);
}
