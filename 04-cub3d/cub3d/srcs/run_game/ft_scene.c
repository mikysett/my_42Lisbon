/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:49:26 by msessa            #+#    #+#             */
/*   Updated: 2021/04/11 01:36:34 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

int	ft_get_white_color(int brightness)
{
	int	color;

	color = 0x00000000;
	color += brightness;
	color += brightness << 8;
	color += brightness << 16;
	// printf("color: %d\n", color);
	return (color);
}

void	ft_draw_bg(t_game *game, int half_height)
{
	ft_draw_rect(&game->scene,
		(t_size){x : 0, y : 0},
		(t_size){x : game->res.x, y : half_height}, 0x00000044);
	ft_draw_rect(&game->scene,
		(t_size){x : 0, y : half_height},
		(t_size){x : game->res.x, y : half_height}, 0x0011AA00);
}

void	ft_draw_tex(t_game *game)
{
	t_vert_line	*line;
	int			i;
	char		*scene_addr;
	char		*tex_addr;
	int			size_line;

	line = &game->line;
	size_line = line->tex->size_line;
	tex_addr = line->tex_addr;
	scene_addr = game->scene.img_addr + (line->pos.x * 4)
		+ line->pos.y * game->scene.size_line;
	i = 0;
	while (i < line->tex_h)
	{
		*(int *)scene_addr = *(int *)tex_addr;
		if (line->next_step_h >= 10000000)
		{
			line->next_step_h -= 10000000;
			tex_addr += line->tex_step_h + size_line;
		}
		else
			tex_addr += line->tex_step_h;
		line->next_step_h += line->step_precision;
		// printf("line->next_step_h: %4d | ", line->next_step_h);
		scene_addr += game->scene.size_line;
		i++;
	}
	// printf("\nStep precision: %d\n", line->step_precision);
	// printf("Step tex_step_h_float: %f\n", line->tex_step_h_float);
}

void	ft_init_line(t_game *game, t_ray *ray, int scene_h, int pos_x)
{
	t_vert_line	*line;

	line = &game->line;
	line->scene_h = scene_h;
	line->line_h = scene_h / ray->dist;
	line->tex = &game->tex[ray->tex];
	line->tex_addr = line->tex->img_addr
		+ (int)(line->tex->width * ray->tex_pos) * 4;
	line->tex_step_h_float = (double)line->tex->height / line->line_h;
	line->tex_step_h = line->tex->size_line * (int)line->tex_step_h_float;
	line->step_precision = (line->tex_step_h_float
		- (int)line->tex_step_h_float) * 10000000;
	line->next_step_h = line->step_precision;
	if (line->line_h > scene_h)
	{
		line->tex_h = scene_h;
		// Offset could be removed because used on only one occasion right now
		// Leaving because it may be useful in the future
		line->offset = (line->line_h - scene_h) / 2.0;
		line->skip_texels = line->offset * line->tex_step_h_float;
		line->tex_addr += line->tex->size_line * (int)(line->skip_texels);
		line->next_step_h = ((line->skip_texels)
			- (int)(line->skip_texels)) * 10000000;
	}
	else
	{
		line->next_step_h = line->step_precision;
		line->tex_h = line->line_h;
		line->offset = 0;
	}
	line->pos.x = pos_x;
	line->pos.y = (scene_h - line->tex_h) / 2;
}

void	ft_scene(t_game *game)
{
	int		half_height;
	int		i;

	half_height = game->res.y / 2;
	ft_draw_bg(game, half_height);
	i = 0;
	while (i < game->res.x)
	{
		ft_init_line(game, &game->rays[i], game->res.y, i);
		// // line_height = game->res.y / game->rays[i].dist;
		// // if (line_height > game->res.y)
		// // 	line_height = game->res.y;
		
		// For shade related to distance in grayscale
		// if (game->rays[i].dist <= 1)
		// 	square_color = 255;
		// else
		// 	square_color = 255 / game->rays[i].dist;
		// // To check texture position on the box
		// square_color = 255 / game->rays[i].tex_pos;

		// // pos.x = i;
		// // pos.y = half_height - line_height / 2;
		// ft_draw_rect(&game->scene, pos, line_height, ft_get_white_color(square_color));
		ft_draw_tex(game);
		// ft_draw_rect(&game->scene, pos, line_height, game->rays[i].color);
		i++;
	}
}