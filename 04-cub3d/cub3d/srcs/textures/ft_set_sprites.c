/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:21:10 by msessa            #+#    #+#             */
/*   Updated: 2021/04/18 20:11:01 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_sprites_visibility(t_game *game)
{
	t_size_f	f_ray_dir;
	t_size_f	l_ray_dir;
	t_sprite	*s;
	int			i;
	int			nb_visibles;

	// calculate angle for visibility
	f_ray_dir.x = game->rays->dir + 0.7;
	f_ray_dir.y = game->rays->dir - 0.7;
	l_ray_dir.x = game->rays[game->res.x - 1].dir + 0.7;
	l_ray_dir.y = game->rays[game->res.x - 1].dir - 0.7;
	i = 0;
	s = game->sprites;
	while (i < game->nb_sprites)
	{
		if ((f_ray_dir.x < l_ray_dir.x &&
			s->angle > f_ray_dir.x && s->angle < l_ray_dir.y)
			|| (f_ray_dir.x > l_ray_dir.x &&
			s->angle > f_ray_dir.y && s->angle < l_ray_dir.x))
			s->in_fov = false;
		else
		{
			s->in_fov = true;
		}
		s++;
		i++;
	}
}

void	ft_set_sprites(t_game *game)
{
	t_sprite	*s;
	int			i;

	i = 0;
	s = game->sprites;
	while (i < game->nb_sprites)
	{
		s->angle = DEGREES_90 + atan2(game->player->f_pos.x - s->f_pos.x,
				game->player->f_pos.y - s->f_pos.y);
		if (s->f_pos.y > game->player->f_pos.y
			&& s->f_pos.x > game->player->f_pos.x)
			s->angle = FULL_CIRCLE + s->angle;
		s++;
		i++;
	}
	ft_sprites_visibility(game);

	// calculate distance

	// go for it!
}