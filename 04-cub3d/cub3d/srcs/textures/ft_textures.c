/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:55:26 by msessa            #+#    #+#             */
/*   Updated: 2021/04/18 17:55:28 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_draw_sky(t_game *game, t_vert_line *line,
	char *scene_addr, char *wall_addr)
{
	char	*sky_addr;
	int		next_step_h;
	int		sky_pos_x;

	if (line->ray->dir < 0)
		line->ray->dir += FULL_CIRCLE;
	else if (line->ray->dir >= FULL_CIRCLE)
		line->ray->dir -= FULL_CIRCLE;
	sky_pos_x = (int)(game->sky_tex.width * (line->ray->dir / FULL_CIRCLE)) * 4;
	sky_addr = game->sky_tex.img_addr + sky_pos_x;
	next_step_h = game->sky_info.step_precision;

	while (scene_addr < wall_addr)
	{
		*(int *)scene_addr = *(int *)sky_addr;
		if (next_step_h >= TEX_PRECISION)
		{
			next_step_h -= TEX_PRECISION;
			sky_addr += game->sky_info.step_h + game->sky_tex.size_line;
		}
		else
			sky_addr += game->sky_info.step_h;
		next_step_h += game->sky_info.step_precision;
		scene_addr += game->scene.size_line;
	}
}

void	ft_draw_ceil(t_game *game, t_vert_line *line,
	char *scene_addr, char *wall_addr)
{
	if (game->sky_tex.img_ref)
		ft_draw_sky(game, line, scene_addr, wall_addr);
	else
		while (scene_addr < wall_addr)
		{
			*(int *)scene_addr = game->ceil_clr;
			scene_addr += game->scene.size_line;
		}
}

void	ft_draw_floor(t_game *game, t_vert_line *line,
	char *floor_addr, int floor_size)
{
	int	floor_alpha;

	if (line->tex_alpha < 2 << 24)
		floor_alpha = 1 << 24;
	else
		floor_alpha = line->tex_alpha - (1 << 24);
	while (floor_alpha != 1 << 24 && floor_size-- > 0)
	{
		*(int *)floor_addr = game->floor_clr | floor_alpha;
		floor_alpha -= (1 << 24);
		floor_addr += game->scene.size_line;
	}
	while (floor_size-- > 0)
	{
		*(int *)floor_addr = game->floor_clr;
		floor_addr += game->scene.size_line;
	}
}

void	ft_draw_line(t_game *game, t_vert_line *line, int tex_size_line)
{
	int			i;
	char		*tex_addr;
	char		*scene_addr;
	char		*wall_addr;

	tex_addr = line->tex_addr;
	scene_addr = game->scene.img_addr + (line->pos.x * 4);
	wall_addr = scene_addr + line->pos.y * game->scene.size_line;
	if (scene_addr != wall_addr)
		ft_draw_ceil(game, line, scene_addr, wall_addr);
	i = 0;
	while (i++ < line->tex_h)
	{
		*(int *)wall_addr = *(int *)tex_addr | line->tex_alpha;
		if (line->next_step_h >= TEX_PRECISION)
		{
			line->next_step_h -= TEX_PRECISION;
			tex_addr += line->tex_step_h + tex_size_line;
		}
		else
			tex_addr += line->tex_step_h;
		line->next_step_h += line->step_precision;
		wall_addr += game->scene.size_line;
	}
	if (line->pos.y > 0)
		ft_draw_floor(game, line, wall_addr, line->pos.y);
}
