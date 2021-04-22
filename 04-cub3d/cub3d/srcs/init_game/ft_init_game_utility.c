/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_utility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 10:06:47 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 19:05:21 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

t_size	ft_init_res(t_list **map_params)
{
	t_map_par	*res;
	t_size		max_size;

	max_size.x = MAX_RES_X;
	max_size.y = MAX_RES_Y;
	res = ft_get_map_param(map_params, resolution);
	if (res->val.res.x > max_size.x)
		res->val.res.x = max_size.x;
	if (res->val.res.y > max_size.y)
		res->val.res.y = max_size.y;
	return (res->val.res);
}

t_player	*ft_ply_init(t_player *player)
{
	int	i;

	i = 0;
	player->last_pos = (t_size){.x = 0, .y = 0};
	player->last_cell_pos = (t_size){.x = 0, .y = 0};
	player->rotating[r_left] = false;
	player->rotating[r_right] = false;
	while (i < NB_DIRECTIONS)
	{
		player->moving[i] = false;
		i++;
	}
	return (player);
}

void	ft_init_bg(t_game *game)
{
	t_map_par	*clr_sel;

	clr_sel = ft_get_map_param(game->map->map_params, ceiling_col);
	game->ceil_clr = clr_sel->val.clr;
	clr_sel = ft_get_map_param(game->map->map_params, floor_col);
	game->floor_clr = clr_sel->val.clr;
}
