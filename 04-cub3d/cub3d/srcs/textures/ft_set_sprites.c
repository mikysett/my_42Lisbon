/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:21:10 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 17:36:06 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_item_picked(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	game->map->map_grid[x][y].type = e_floor;
	while (i < game->nb_sprites)
	{
		if (game->sprites[i].pos.x == x && game->sprites[i].pos.y == y)
			game->sprites[i].is_picked = true;
		i++;
	}
}

static void	ft_sprites_visibility(t_game *game, t_sprite *s,
	int nb_visibles, int i)
{
	const double	f_ray_dir = game->rays->dir + DEG_45;
	const double	l_ray_dir = game->rays[game->res.x - 1].dir - DEG_45;
	t_sprite		s_buf;

	while (i < game->nb_sprites)
	{
		s->in_fov = true;
		if (s->is_picked || (f_ray_dir > l_ray_dir
				&& (s->angle > f_ray_dir || s->angle < l_ray_dir))
			|| (f_ray_dir < l_ray_dir
				&& (s->angle > f_ray_dir && s->angle < l_ray_dir)))
			s->in_fov = false;
		else if (i != nb_visibles)
		{
			s_buf = game->sprites[nb_visibles];
			game->sprites[nb_visibles] = *s;
			*s = s_buf;
			nb_visibles++;
		}
		else
			nb_visibles++;
		s++;
		i++;
	}
}

static void	ft_sprites_distance(t_game *game, t_sprite *s)
{
	int	i;

	i = 0;
	while (i < game->nb_sprites)
	{
		if (!s->in_fov)
			return ;
		if (s->angle <= DEG_180)
			s->angle_x_axis = DEG_180 - s->angle;
		else
			s->angle_x_axis = s->angle - DEG_180;
		s->angle_plane = game->player->dir + DEG_90 - s->angle;
		s->e_dist = (game->player->f_pos.x - s->start_pos.x)
			/ cos(s->angle_x_axis);
		s->dist = sin(s->angle_plane) * s->e_dist;
		if (game->rays[0].dir < DEG_180 && s->angle > DEG_180)
			s->ray_index = (int)((game->rays[0].dir + FULL_CIRCLE - s->angle)
					/ game->rays_info.step);
		else
			s->ray_index = (int)((game->rays[0].dir - s->angle)
					/ game->rays_info.step);
		s++;
		i++;
	}
}

void	ft_set_sprites(t_game *game)
{
	t_sprite		*s;
	int				i;
	const double	plan_rad = game->player->dir - DEG_90;

	i = 0;
	s = game->sprites;
	while (i < game->nb_sprites)
	{
		s->start_pos.x = s->f_pos.x - cos(plan_rad) * 0.5;
		s->start_pos.y = s->f_pos.y + sin(plan_rad) * 0.5;
		s->angle = DEG_90 + atan2(game->player->f_pos.x - s->start_pos.x,
				game->player->f_pos.y - s->start_pos.y);
		if (s->start_pos.y > game->player->f_pos.y
			&& s->start_pos.x > game->player->f_pos.x)
			s->angle = FULL_CIRCLE + s->angle;
		s++;
		i++;
	}
	ft_sprites_visibility(game, game->sprites, 0, 0);
	ft_sprites_distance(game, game->sprites);
}
