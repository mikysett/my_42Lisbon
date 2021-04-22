/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 19:36:29 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 14:18:09 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static void	ft_game_update(t_game *game)
{
	t_size	move;

	move = ft_ply_set_move(game, game->player->dir, game->player->moving);
	ft_ply_set_cell_x(game, game->player, move);
	ft_ply_set_cell_y(game, game->player, move);
	if (game->player->rotating[r_left] || game->player->rotating[r_right])
		ft_ply_set_dir(game, game->player);
	ft_rays_set(game, game->rays, game->res.x, game->rays_info.step);
	ft_scene(game);
	if (game->settings[show_minimap])
		ft_mini_map(game);
}

static void	ft_game_print(t_game *game)
{
	// Black bg for transparency, flickering on linux, ok on mac
	mlx_put_image_to_window(game->mlx, game->win, game->bg.img_ref, 0, 0);
	if (ft_player_moved(game->player))
		ft_game_update(game);
	mlx_put_image_to_window(game->mlx, game->win, game->scene.img_ref, 0, 0);
	// Extra layer for objects, don't sure it will be useful
	// Maybe for putting black on scene and transparency on objects
	// mlx_put_image_to_window(game->mlx, game->win, game->obj.img_ref, 0, 0);
	if (game->settings[show_minimap])
	{
		mlx_put_image_to_window(game->mlx, game->win, game->mm_img.img_ref,
			game->mm_pos.x, game->mm_pos.y);
		mlx_put_image_to_window(game->mlx, game->win, game->lb.img.img_ref,
			game->lb.pos.x, game->lb.pos.y);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->lb.img.img_ref,
			game->lb.pos.x, game->mm_pos.y + game->mini_map.size.y / 2);
	ft_update_time(game);
	if (game->settings[show_fps])
		ft_print_fps(game);
}

int	ft_render_game(void *game_void)
{
	t_game	*game;

	game = (t_game *)game_void;
	ft_game_print(game);
	return (1);
}

void	ft_run_game(t_map *map)
{
	t_game	game;

	if (!ft_init_game(&game, map))
		return ;
	ft_set_events(&game);
	ft_game_update(&game);
	ft_lifeb_update(&game);
	mlx_loop(game.mlx);
}