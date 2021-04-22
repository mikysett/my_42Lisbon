/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:39:18 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 12:28:11 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static void	ft_sort_sprites(t_game *game)
{
	int			i;
	int			j;
	t_sprite	s_buf;

	i = 0;
	while (i < game->nb_sprites)
	{
		if (!game->sprites[i].in_fov)
			return ;
		j = i + 1;
		while (j < game->nb_sprites)
		{
			if (!game->sprites[j].in_fov)
				break ;
			if (game->sprites[i].dist < game->sprites[j].dist)
			{
				s_buf = game->sprites[j];
				game->sprites[j] = game->sprites[i];
				game->sprites[i] = s_buf;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_sprite_info(t_game *game, t_sprite *s)
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

void	ft_draw_sprite_line(t_game *game, t_sprite *s, char *obj_addr)
{
	char	*print_addr;
	int		i;

	i = 0;
	print_addr = obj_addr + s->screen_pos_y * game->scene.size_line;
	while (i < s->height && i + s->screen_pos_y < game->res.y)
	{
		if (*(unsigned int *)s->sprite_addr >> 24 != 0xFF)
			*(int *)print_addr = *(int *)s->sprite_addr;
		if (s->next_step_h >= TEX_PRECISION)
		{
			s->next_step_h -= TEX_PRECISION;
			s->sprite_addr += s->step_h + s->img->size_line;
		}
		else
			s->sprite_addr += s->step_h;
		s->next_step_h += s->step_precision;
		print_addr += game->scene.size_line;
		i++;
	}
}

void	ft_draw_sgl_sprite(t_game *game, t_sprite *s)
{
	char	*obj_addr;

	ft_init_sprite_info(game, s);
	// Can't decide between two layers and one only
	obj_addr = game->scene.img_addr + (s->ray_index * 4);
	while (s->tex_pos_x <= 1 && s->ray_index < game->res.x)
	{
		if (s->ray_index >= game->res.x)
			return ;
		if (s->ray_index >= 0 && game->rays[s->ray_index].dist > s->dist)
		{
			s->sprite_addr = s->img->img_addr
				+ (int)(s->img->width * s->tex_pos_x) * 4;
			if (s->height > game->res.y)
			{
				s->sprite_addr += s->skipped_pix;
				s->next_step_h = s->init_next_step_h;
			}
			else
				s->next_step_h = s->step_precision;
			ft_draw_sprite_line(game, s, obj_addr);
		}
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
