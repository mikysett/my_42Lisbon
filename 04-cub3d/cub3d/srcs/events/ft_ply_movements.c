/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ply_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:14:02 by msessa            #+#    #+#             */
/*   Updated: 2021/04/14 16:48:38 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

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

t_size	ft_ply_set_move(double move_dir, bool *moving)
{
	if (moving[d_t] == true)
	{
		if (moving[d_l] == true)
			move_dir += DEGREES_45;
		if (moving[d_r] == true)
			move_dir -= DEGREES_45;
	}
	else if (moving[d_b] == true)
	{
		move_dir += DEGREES_180;
		if (moving[d_l] == true)
			move_dir -= DEGREES_45;
		if (moving[d_r] == true)
			move_dir += DEGREES_45;
	}
	else if (moving[d_l] == true)
		move_dir += DEGREES_90;
	else if (moving[d_r] == true)
		move_dir -= DEGREES_90;
	else
		return ((t_size){x : 0, y : 0});
	return ((t_size){x : cos(move_dir) * WALK_STEP,
		y : -(int)(sin(move_dir) * WALK_STEP)});
}

void		ft_ply_set_cell_x(t_map *map, t_player *player, t_size move)
{
	int	new_cell_pos_x;

	new_cell_pos_x = player->cell_pos.x + move.x;
	if (new_cell_pos_x < 0)
	{
		if (map->map_grid[player->pos.x - 1][player->pos.y].type == e_floor)
		{
			player->pos.x -= 1;
			player->cell_pos.x = NB_CELL_POS + new_cell_pos_x;
		}
		else
			player->cell_pos.x = 1;
	}
	else if (new_cell_pos_x >= NB_CELL_POS)
	{
		if (map->map_grid[player->pos.x + 1][player->pos.y].type == e_floor)
		{
			player->pos.x += 1;
			player->cell_pos.x = new_cell_pos_x - NB_CELL_POS;
		}
		else
			player->cell_pos.x = NB_CELL_POS - 2;
	}
	else
		player->cell_pos.x = new_cell_pos_x;
}

void		ft_ply_set_cell_y(t_map *map, t_player *player, t_size move)
{
	int	new_cell_pos_y;

	new_cell_pos_y = player->cell_pos.y + move.y;
	if (new_cell_pos_y < 0)
	{
		if (map->map_grid[player->pos.x][player->pos.y - 1].type == e_floor)
		{
			player->pos.y -= 1;
			player->cell_pos.y = NB_CELL_POS + new_cell_pos_y;
		}
		else
			player->cell_pos.y = 1;
	}
	else if (new_cell_pos_y >= NB_CELL_POS)
	{
		if (map->map_grid[player->pos.x][player->pos.y + 1].type == e_floor)
		{
			player->pos.y += 1;
			player->cell_pos.y = new_cell_pos_y - NB_CELL_POS;
		}
		else
			player->cell_pos.y = NB_CELL_POS - 2;
	}
	else
		player->cell_pos.y = new_cell_pos_y;
}

void	ft_ply_set_dir(t_player *player)
{
	if (player->rotating[r_left] == true)
		player->dir += ROTATION_DEG;
	if (player->rotating[r_right] == true)
		player->dir -= ROTATION_DEG;
	if (player->dir < 0)
		player->dir = FULL_CIRCLE + player->dir;
	else if (player->dir > FULL_CIRCLE)
		player->dir = player->dir - FULL_CIRCLE;
}
