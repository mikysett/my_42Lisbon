/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:49:26 by msessa            #+#    #+#             */
/*   Updated: 2021/04/18 16:14:54 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static void	ft_set_line_offset(t_vert_line *line, int scene_h)
{
	if (line->line_h > scene_h)
	{
		line->tex_h = scene_h;
		// Offset could be removed because used on only one occasion right now
		// Leaving because it may be useful in the future
		line->offset = (line->line_h - scene_h) / 2.0;
		line->skip_texels = line->offset * line->tex_step_h_float;
		line->tex_addr += line->tex->size_line * (int)(line->skip_texels);
		line->next_step_h = (line->skip_texels - (int)(line->skip_texels))
			* TEX_PRECISION;
	}
	else
	{
		line->next_step_h = line->step_precision;
		line->tex_h = line->line_h;
		line->offset = 0;
	}
}

static void	ft_init_line(t_game *game, t_ray *ray, int scene_h, int pos_x)
{
	t_vert_line	*line;

	line = &game->line;
	line->ray = ray;
	line->scene_h = scene_h;
	if (ray->dist <= 0)
		line->line_h = scene_h * 20;
	else
		line->line_h = scene_h / ray->dist;
	line->tex = &game->tex[ray->tex];
	line->tex_addr = line->tex->img_addr
		+ (int)(line->tex->width * ray->tex_pos) * 4;
	line->tex_step_h_float = (double)line->tex->height / line->line_h;
	line->tex_step_h = line->tex->size_line * (int)line->tex_step_h_float;
	line->step_precision = (line->tex_step_h_float
		- (int)line->tex_step_h_float) * TEX_PRECISION;
	line->next_step_h = line->step_precision;
	ft_set_line_offset(line, scene_h);
	line->pos.x = pos_x;
	line->pos.y = (scene_h - line->tex_h) / 2;

	if (ray->dist <= 1)
		line->tex_alpha = 0;
	if (ray->dist > 12.75)
		line->tex_alpha = 255 << 24;
	else
		line->tex_alpha = (unsigned int)(ray->dist * 20) << 24;
}

void	ft_scene(t_game *game)
{
	t_vert_line	*line;
	int			i;

	line = &game->line;
	i = 0;
	while (i < game->res.x)
	{
		ft_init_line(game, &game->rays[i], game->res.y, i);
		ft_draw_line(game, line, line->tex->size_line);
		i++;
	}
	// Draw Sprites
	if (game->sprites)
	{
		ft_draw_sprites(game);
		ft_print_sprites_info(game->sprites, game->nb_sprites);
		// printf("----------------------------\n");
		// ft_lstclear(game->sprites, ft_clear_sprites);
	}
}