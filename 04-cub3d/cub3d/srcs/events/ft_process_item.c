/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_item.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:20:54 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 17:23:18 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static void	ft_update_status(t_game *game, t_status status)
{
	if (status == dead)
	{
		game->status = dead;
		game->player->moving[d_l] = false;
		game->player->moving[d_r] = false;
		game->player->moving[d_t] = false;
		game->player->moving[d_b] = false;
		game->player->rotating[r_left] = false;
		game->player->rotating[r_right] = false;
	}
}

bool	ft_process_item(t_game *game, int x, int y)
{
	const t_map_el_type	item_type = game->map->map_grid[x][y].type;

	if (item_type == e_floor)
		return (true);
	if (item_type == trap)
	{
		game->player->life -= LIFE_DOWN_STEP;
		if (game->player->life <= 0)
		{
			game->player->life = 0;
			ft_update_status(game, dead);
		}
		ft_item_picked(game, x, y);
		ft_lifeb_update(game);
	}
	else if (item_type == heal)
	{
		game->player->life += LIFE_UP_STEP;
		if (game->player->life > 100)
			game->player->life = 100;
		ft_item_picked(game, x, y);
		ft_lifeb_update(game);
	}
	return (false);
}
