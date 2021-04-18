/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:54:56 by msessa            #+#    #+#             */
/*   Updated: 2021/04/14 18:58:39 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static void	ft_del_map_param(void *p)
{
	t_map_par	*param;

	param = (t_map_par *)p;
	if ((param->type >= nord_tex && param->type <= trap_tex)
		|| param->type == skybox_tex)
		free(param->val.texture);
	free(param);
}

t_map	*ft_free_map(t_map *map)
{
	if (map->map_params)
	{
		ft_lstclear(map->map_params, &ft_del_map_param);
		free(map->map_params);
	}
	if (map->map_grid)
		ft_free_matrix((void **)map->map_grid, map->map_size.x);
	free(map);
	return (0);
}

void	ft_free_map_file(t_list	**map_lines)
{
	if (map_lines)
	{
		ft_lstclear(map_lines, &free);
		free(map_lines);
	}
}

t_map	*ft_alloc_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_error(err_map_malloc);
		return (0);
	}
	map->map_params = malloc(sizeof(t_list *));
	if (!(map->map_params))
	{
		free(map);
		ft_error(err_map_malloc);
		return (0);
	}
	map->map_params[0] = 0;
	map->map_grid = 0;
	map->map_size.x = 0;
	map->map_size.y = 0;
	return (map);
}
