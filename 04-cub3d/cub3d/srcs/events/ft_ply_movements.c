/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ply_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:14:02 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 19:05:21 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

bool	ft_player_moved(t_player *p)
{
	int	i;

	if (p->rotating[r_left] == true
		|| p->rotating[r_right] == true)
		return (true);
	i = 0;
	while (i < NB_DIRECTIONS)
	{
		if (p->moving[i] == true)
			return (true);
		i++;
	}
	return (false);
}

t_size	ft_ply_set_move(t_game *game, double move_dir, bool *moving)
{
	if (moving[d_t] == true)
	{
		if (moving[d_l] == true)
			move_dir += DEG_45;
		if (moving[d_r] == true)
			move_dir -= DEG_45;
	}
	else if (moving[d_b] == true)
	{
		move_dir += DEG_180;
		if (moving[d_l] == true)
			move_dir -= DEG_45;
		if (moving[d_r] == true)
			move_dir += DEG_45;
	}
	else if (moving[d_l] == true)
		move_dir += DEG_90;
	else if (moving[d_r] == true)
		move_dir -= DEG_90;
	else
		return ((t_size){.x = 0, .y = 0});
	return ((t_size){.x = cos(move_dir) * (WALK_STEP * game->delta_time),
		.y = -(int)(sin(move_dir) * (WALK_STEP * game->delta_time))});
}

void	ft_ply_set_cell_x(t_game *game, t_player *p, t_size move)
{
	int	new_cell_pos_x;

	new_cell_pos_x = p->cell_pos.x + move.x;
	if (new_cell_pos_x < 0)
	{
		if (ft_process_item(game, p->pos.x - 1, p->pos.y))
		{
			p->pos.x -= 1;
			p->cell_pos.x = NB_CELL_POS + new_cell_pos_x;
		}
		else
			p->cell_pos.x = 1;
	}
	else if (new_cell_pos_x >= NB_CELL_POS)
	{
		if (ft_process_item(game, p->pos.x + 1, p->pos.y))
		{
			p->pos.x += 1;
			p->cell_pos.x = new_cell_pos_x - NB_CELL_POS;
		}
		else
			p->cell_pos.x = NB_CELL_POS - 2;
	}
	else
		p->cell_pos.x = new_cell_pos_x;
}

void	ft_ply_set_cell_y(t_game *game, t_player *p, t_size move)
{
	int	new_cell_pos_y;

	new_cell_pos_y = p->cell_pos.y + move.y;
	if (new_cell_pos_y < 0)
	{
		if (ft_process_item(game, p->pos.x, p->pos.y - 1))
		{
			p->pos.y -= 1;
			p->cell_pos.y = NB_CELL_POS + new_cell_pos_y;
		}
		else
			p->cell_pos.y = 1;
	}
	else if (new_cell_pos_y >= NB_CELL_POS)
	{
		if (ft_process_item(game, p->pos.x, p->pos.y + 1))
		{
			p->pos.y += 1;
			p->cell_pos.y = new_cell_pos_y - NB_CELL_POS;
		}
		else
			p->cell_pos.y = NB_CELL_POS - 2;
	}
	else
		p->cell_pos.y = new_cell_pos_y;
}

void	ft_ply_set_dir(t_game *game, t_player *p)
{
	if (p->rotating[r_left] == true)
		p->dir += (ROTATION_DEG * game->delta_time);
	if (p->rotating[r_right] == true)
		p->dir -= (ROTATION_DEG * game->delta_time);
	if (p->dir < 0)
		p->dir = FULL_CIRCLE + p->dir;
	else if (p->dir > FULL_CIRCLE)
		p->dir = p->dir - FULL_CIRCLE;
}
