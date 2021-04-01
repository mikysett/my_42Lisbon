/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:36:30 by msessa            #+#    #+#             */
/*   Updated: 2021/04/01 20:39:03 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

int	ft_exit_game(int key, void *game)
{
	printf("exit game\n");
	exit(EXIT_SUCCESS);
	(void)key;
	ft_free_game((t_game *)game);
	return (1);
}

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
	printf("key: %d\n", key);
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

bool	ft_player_moved(t_player *player)
{
	int	i;

	if (player->rotating[r_left] == true
		|| player->rotating[r_right] == true)
		return (true);
	i = 0;
	while (i < NB_DIRECTIONS)
	{
		if (player->moving[i] == true)
			return (true);
		i++;
	}
	return (false);
}

t_size	ft_ply_take_move(bool *moving)
{
	t_size	move;
	int		diagonal_fix;

	move = (t_size){x : 0, y : 0};
	if (moving[d_l] == true)
		move.x -= WALKING_STEPS;
	if (moving[d_r] == true)
		move.x += WALKING_STEPS;
	if (moving[d_t] == true)
		move.y -= WALKING_STEPS;
	if (moving[d_b] == true)
		move.y += WALKING_STEPS;
	if (move.x != 0 && move.y != 0)
	{
		diagonal_fix = WALKING_STEPS / 2;
		if (move.x > 0)
			move.x -= diagonal_fix;
		else
			move.x += diagonal_fix;
		if (move.y > 0)
			move.y -= diagonal_fix;
		else
			move.y += diagonal_fix;
	}
	return (move);
}

void	ft_ply_moving(t_map *map, t_player *player, t_size move)
{
	t_size	new_cell_pos;

	// printf("moving steps: x: %d, d: %d\n", move.x, move.y);
	new_cell_pos.x = player->cell_pos.x + move.x;
	new_cell_pos.y = player->cell_pos.y + move.y;
	if (new_cell_pos.x < 0)
	{
		if (map->map_grid[player->pos.x - 1][player->pos.y].type != wall)
		{
			player->pos.x -= 1;
			player->cell_pos.x = NB_CELL_POS + new_cell_pos.x;
		}
	}
	else if (new_cell_pos.x >= NB_CELL_POS)
	{
		if (map->map_grid[player->pos.x + 1][player->pos.y].type != wall)
		{
			player->pos.x += 1;
			player->cell_pos.x = new_cell_pos.x - NB_CELL_POS;
		}
	}
	else
		player->cell_pos.x = new_cell_pos.x;
	if (new_cell_pos.y < 0)
	{
		if (map->map_grid[player->pos.x][player->pos.y - 1].type != wall)
		{
			player->pos.y -= 1;
			player->cell_pos.y = NB_CELL_POS + new_cell_pos.y;
		}
	}
	else if (new_cell_pos.y >= NB_CELL_POS)
	{
		if (map->map_grid[player->pos.x][player->pos.y + 1].type != wall)
		{
			player->pos.y += 1;
			player->cell_pos.y = new_cell_pos.y - NB_CELL_POS;
		}
	}
	else
		player->cell_pos.y = new_cell_pos.y;
}

void	ft_set_events(t_game *game)
{
	// mlx_do_key_autorepeatoff(game->mlx);
	mlx_hook(game->win, KEY_PRESS, KEY_PRESS_M, ft_key_press, (void *)game);
	mlx_hook(game->win, KEY_RELEASE, KEY_RELEASE_M, ft_key_release, (void *)game);
	mlx_hook(game->win, DESTROY_NOTIFY, DESTROY_NOTIFY_M, ft_exit_game, (void *)game);
	mlx_loop_hook(game->mlx, ft_render_game, (void *)game);
}