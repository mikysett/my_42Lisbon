/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:36:29 by msessa            #+#    #+#             */
/*   Updated: 2021/04/01 20:38:16 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"


void	ft_game_print(t_game *game)
{
	ft_ply_moving(game->map, game->player,
		ft_ply_take_move(game->player->moving));
	if (game->player->rotating[r_left] || game->player->rotating[r_right])
		ft_ply_direction(game->player);
	ft_mini_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->mm_img.img_ref,
		game->mm_pos.x, game->mm_pos.y);
}

int	ft_render_game(void *game_void)
{
	t_game	*game;

	game = (t_game *)game_void;
	if (ft_player_moved(game->player))
		ft_game_print(game);
	return (1);
}

void	ft_run_game(t_map *map)
{
	t_game	game;

	if (!ft_init_game(&game, map))
		return ;
	ft_set_events(&game);
	ft_game_print(&game);
	mlx_loop(game.mlx);
}