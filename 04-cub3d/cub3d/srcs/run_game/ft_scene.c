/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:49:26 by msessa            #+#    #+#             */
/*   Updated: 2021/04/09 21:28:34 by msessa           ###   ########.fr       */
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

void	ft_draw_tex(t_game *game, t_ray *ray,
	const t_size pos, const int tex_height)
{
	int			i;
	char		*img_addr;
	t_img_data	*tex;
	const int	step_y = game->scene.size_line;
	int			color;
	int			tex_x_pos;

	img_addr = game->scene.img_addr + (pos.x * 4)
		+ pos.y * game->scene.size_line;
	tex = &game->tex[ray->tex];
	tex_x_pos = (int)(TEX_SIZE * ray->tex_pos) * 4;
	i = 0;
	while (i < tex_height)
	{
		if (i / 4 < tex->height)
		{
			color = *(int *)&(tex->
			img_addr[tex_x_pos + tex->size_line * (i / 4)]);
			*((int *)(img_addr)) = color;
		}
		else
			*((int *)(img_addr)) = 0x00FFFFFF;
		img_addr += step_y;
		i++;
	}
}

void	ft_scene(t_game *game)
{
	int		line_height;
	int		square_color;
	int		half_height;
	int		i;
	t_size	pos;

	half_height = game->res.y / 2;
	ft_draw_bg(game, half_height);
	i = 0;
	while (i < game->res.x)
	{
		line_height = game->res.y / game->rays[i].dist;
		if (line_height > game->res.y)
			line_height = game->res.y;
		
		// For shade related to distance in grayscale
		if (game->rays[i].dist <= 1)
			square_color = 255;
		else
			square_color = 255 / game->rays[i].dist;
		// To check texture position on the box
		square_color = 255 / game->rays[i].tex_pos;

		pos.x = i;
		pos.y = half_height - line_height / 2;
		// ft_draw_rect(&game->scene, pos, line_height, ft_get_white_color(square_color));
		ft_draw_tex(game, &game->rays[i], pos, line_height);
		// ft_draw_rect(&game->scene, pos, line_height, game->rays[i].color);
		i++;
	}
}