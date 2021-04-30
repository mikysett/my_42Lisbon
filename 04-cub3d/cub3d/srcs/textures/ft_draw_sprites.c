/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:39:18 by msessa            #+#    #+#             */
/*   Updated: 2021/04/28 15:36:19 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static void	ft_init_sprite_info(t_game *game, t_sprite *s)
{
	s->tex_pos_x = 0;
	s->height = game->res.y / s->dist;
	s->step_x = (tan(game->rays_info.step) * s->dist)
		/ cos(DEG_90 - s->angle_plane);
	s->step_h_f = (double)s->img->height / s->height;
	s->step_h = s->img->size_line * (int)s->step_h_f;
	s->step_precision = (s->step_h_f - (int)s->step_h_f) * TEX_PRECISION;
	if (s->height > game->res.y)
	{
		s->tex_h = game->res.y;
		s->skip_texels = ((s->height - game->res.y) / 2.0)
			* s->step_h_f;
		s->skipped_pix = s->img->size_line
			* (int)(s->skip_texels);
		s->init_next_step_h = (s->skip_texels - (int)(s->skip_texels))
			* TEX_PRECISION;
		s->screen_pos_y = 0;
	}
	else
	{
		s->next_step_h = s->step_precision;
		s->tex_h = s->height;
		s->screen_pos_y = (game->res.y - s->height) / 2;
	}
}

static void	ft_draw_sprite_line(t_game *game, t_sprite *s,
	char *scene_addr, char *obj_addr)
{
	int		i;

	i = 0;
	scene_addr += s->screen_pos_y * game->scene.size_line;
	obj_addr += s->screen_pos_y * game->scene.size_line;
	while (i < s->height && i + s->screen_pos_y < game->res.y)
	{
		if (*(unsigned int *)s->sprite_addr >> 24 != 0xFF)
		{
			*(int *)scene_addr = 0x00000000;
			*(int *)obj_addr = *(int *)s->sprite_addr | s->tex_alpha;
		}
		if (s->next_step_h >= TEX_PRECISION)
		{
			s->next_step_h -= TEX_PRECISION;
			s->sprite_addr += s->step_h + s->img->size_line;
		}
		else
			s->sprite_addr += s->step_h;
		s->next_step_h += s->step_precision;
		scene_addr += game->scene.size_line;
		obj_addr += game->scene.size_line;
		i++;
	}
}

static void	ft_preprocess_sprite_line(t_game *game, t_sprite *s)
{
	if (s->dist <= 1)
		s->tex_alpha = 0;
	if (s->dist > 12.75)
		s->tex_alpha = 255 << 24;
	else
		s->tex_alpha = (unsigned int)(s->dist * 20) << 24;
	s->sprite_addr = s->img->img_addr
		+ 4 * (int)(s->img->width * s->tex_pos_x);
	if (s->height > game->res.y)
	{
		s->sprite_addr += s->skipped_pix;
		s->next_step_h = s->init_next_step_h;
	}
	else
		s->next_step_h = s->step_precision;
}

static void	ft_draw_sgl_sprite(t_game *game, t_sprite *s)
{
	char	*scene_addr;
	char	*obj_addr;

	ft_init_sprite_info(game, s);
	scene_addr = game->scene.img_addr + (s->ray_index * 4);
	obj_addr = game->obj.img_addr + (s->ray_index * 4);
	while (s->tex_pos_x <= 1 && s->ray_index < game->res.x)
	{
		if (s->ray_index >= game->res.x)
			return ;
		if (s->ray_index >= 0 && game->rays[s->ray_index].dist > s->dist)
		{
			ft_preprocess_sprite_line(game, s);
			ft_draw_sprite_line(game, s, scene_addr, obj_addr);
		}
		scene_addr += 4;
		obj_addr += 4;
		s->ray_index++;
		s->tex_pos_x += s->step_x;
	}
}

void	ft_draw_sprites(t_game *game)
{
	int	i;

	ft_sort_sprites(game);
	i = 0;
	while (i < game->nb_sprites)
	{
		if (!game->sprites[i].in_fov)
			return ;
		ft_draw_sgl_sprite(game, &game->sprites[i]);
		i++;
	}
}
