/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:44:13 by msessa            #+#    #+#             */
/*   Updated: 2021/03/28 19:02:01 by msessa           ###   ########.fr       */
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

static int	ft_set_map(t_list **map_lines, t_map *map)
{
	bool	params_set[MIN_MAP_PARAMS];

	ft_init_params(params_set);
	if (!ft_init_map_param(*map_lines, map, params_set))
		return (false);
	if (!ft_check_params(params_set))
		return (ft_error(err_map_param_miss));
	// to test
	// ft_print_params_set(params_set);
	if (!ft_init_map_size(*map_lines, map))
		return (ft_error(err_map_grid));
	return (1);
}

t_map	*ft_init_map(char *map_path)
{
	t_map	*map;
	t_list	**map_lines;

	map_lines = ft_save_file(map_path);
	if (!map_lines)
		return (0);
	map = ft_alloc_map();
	if (map && !ft_set_map(map_lines, map))
		map = ft_free_map(map);
	if (map && !ft_set_map_grid(*map_lines, map))
		map = ft_free_map(map);
	// to test
	else if (map)
		ft_print_map_grid(map);
	ft_free_map_file(map_lines);
	return (map);
}
