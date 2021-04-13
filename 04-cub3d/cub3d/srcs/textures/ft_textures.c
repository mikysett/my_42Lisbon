/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 09:57:53 by msessa            #+#    #+#             */
/*   Updated: 2021/04/11 20:59:28 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_draw_ceil(t_game *game, t_vert_line *line,
	char *scene_addr, char *wall_addr)
{
	while (scene_addr != wall_addr)
	{
		*(int *)scene_addr = game->ceil_clr;
		scene_addr += game->scene.size_line;
	}
}

void	ft_draw_floor(t_game *game, t_vert_line *line,
	char *floor_addr, int floor_size)
{
	while (floor_size-- != 0)
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
		*(int *)wall_addr = *(int *)tex_addr;
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
		ft_draw_floor(game, line, wall_addr, line->pos.y);
}