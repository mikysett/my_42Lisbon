/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 09:57:53 by msessa            #+#    #+#             */
/*   Updated: 2021/04/13 20:22:18 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_draw_sky(t_game *game, t_vert_line *line,
	char *scene_addr, char *wall_addr)
{
	int		half_height;
	char	*sky_addr;
	double	sky_step_h_float;
	int		sky_step_h;
	int		step_precision;
	int		next_step_h;
	int		sky_pos_x;

	sky_pos_x = (int)(line->tex->width * (line->ray->dir / PI)) * 4;
	sky_addr = game->sky_tex.img_addr + sky_pos_x;
	// line->tex_addr = line->tex->img_addr
	// 	+ (int)(line->tex->width * ray->tex_pos) * 4;
	half_height = game->res.y / 2;
	sky_step_h_float = (double)game->sky_tex.height / half_height;
	sky_step_h = game->sky_tex.size_line * (int)sky_step_h_float;
	step_precision = (sky_step_h_float - (int)sky_step_h_float) * 10000000;
	next_step_h = step_precision;

	while (scene_addr < wall_addr - (game->scene.size_line * 100))
	{
		*(int *)scene_addr = *(int *)sky_addr;
		if (next_step_h >= 10000000)
		{
			next_step_h -= 10000000;
			sky_addr += line->tex_step_h + game->sky_tex.size_line;
		}
		else
			sky_addr += line->tex_step_h;
		next_step_h += line->step_precision;
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
		if (line->sprite)
			*(int *)wall_addr = 0x00AA0000;
		if (line->next_step_h >= 10000000)
		{
			line->next_step_h -= 10000000;
			tex_addr += line->tex_step_h + tex_size_line;
		}
		else
			tex_addr += line->tex_step_h;
		line->next_step_h += line->step_precision;
		wall_addr += game->scene.size_line;
	}
	if (line->pos.y != 0)
		ft_draw_floor(game, line, wall_addr,
		game->res.y - line->pos.y - line->line_h);
}