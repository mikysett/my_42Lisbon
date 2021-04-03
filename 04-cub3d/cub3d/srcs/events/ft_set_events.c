/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:36:30 by msessa            #+#    #+#             */
/*   Updated: 2021/04/02 13:15:10 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

int	ft_key_press(int key, void *game_void)
{
	t_game	*game;
	
	game = (t_game *)game_void;
	printf("key: %d\n", key);
	if (key == KEY_MOV_LEFT)
		game->player->moving[d_l] = true;
	else if (key == KEY_MOV_RIGHT)
		game->player->moving[d_r] = true;
	else if (key == KEY_MOV_UP)
		game->player->moving[d_t] = true;
	else if (key == KEY_MOV_DOWN)
		game->player->moving[d_b] = true;
	else if (key == KEY_ARR_LEFT)
		game->player->rotating[r_left] = true;
	else if (key == KEY_ARR_RIGHT)
		game->player->rotating[r_right] = true;
	else if (key == KEY_ESC)
		ft_exit_game(key, game_void);
	ft_render_game(game);
	return (0);
}

int	ft_key_release(int key, void *game_void)
{
	t_game	*game;
	
	game = (t_game *)game_void;
	if (key == KEY_MOV_LEFT)
		game->player->moving[d_l] = false;
	else if (key == KEY_MOV_RIGHT)
		game->player->moving[d_r] = false;
	else if (key == KEY_MOV_UP)
		game->player->moving[d_t] = false;
	else if (key == KEY_MOV_DOWN)
		game->player->moving[d_b] = false;
	else if (key == KEY_ARR_LEFT)
		game->player->rotating[r_left] = false;
	else if (key == KEY_ARR_RIGHT)
		game->player->rotating[r_right] = false;
	return (0);
}

void	ft_set_events(t_game *game)
{
	// mlx_do_key_autorepeatoff(game->mlx);
	mlx_hook(game->win, KEY_PRESS, KEY_PRESS_M, ft_key_press, (void *)game);
	mlx_hook(game->win, KEY_RELEASE, KEY_RELEASE_M, ft_key_release, (void *)game);
	mlx_hook(game->win, DESTROY_NOTIFY, DESTROY_NOTIFY_M, ft_exit_game, (void *)game);
	mlx_loop_hook(game->mlx, ft_render_game, (void *)game);
}