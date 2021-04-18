/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:39:18 by msessa            #+#    #+#             */
/*   Updated: 2021/04/17 20:25:07 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_clear_sprites(void *void_sprite)
{
	t_sprite	*sprite;
	
	sprite = (t_sprite *)void_sprite;
	sprite->map_el->sprite_done = false;
	free(sprite);
}

int		ft_cmp_sprites(t_sprite *s1, t_sprite *s2)
{
	if (s1->dist > s2->dist)
		return (-1);
	else if (s1->dist < s2->dist)
		return (1);
	return (0);	
}

void	ft_init_sprite_info(t_game *game, t_sprite *sprite)
{
	sprite->height = game->res.y / sprite->dist;
	sprite->step_x = tan(game->rays_info.step) * sprite->dist;
	sprite->step_h_float = (double)sprite->img->height / sprite->height;
	sprite->step_h = sprite->img->size_line * (int)sprite->step_h_float;
	sprite->step_precision = (sprite->step_h_float
		- (int)sprite->step_h_float) * TEX_PRECISION;
	if (sprite->height > game->res.y)
	{
		sprite->tex_h = game->res.y;
		sprite->skip_texels = ((sprite->height - game->res.y) / 2.0)
			* sprite->step_h_float;
		sprite->skipped_pix = sprite->img->size_line
			* (int)(sprite->skip_texels);
		sprite->init_next_step_h = 
			(sprite->skip_texels - (int)(sprite->skip_texels)) * TEX_PRECISION;
		sprite->pos.y = 0;
	}
	else
	{
		sprite->next_step_h = sprite->step_precision;
		sprite->tex_h = sprite->height;
		sprite->pos.y = (game->res.y - sprite->height) / 2;
	}
}

void	ft_draw_sprite_line(t_game *game, t_sprite *sprite, char *obj_addr)
{
	char	*print_addr;
	int		i;

	i = 0;
	print_addr = obj_addr + sprite->pos.y * game->scene.size_line;
	while (i < sprite->height && i + sprite->pos.y < game->res.y)
	{
		if (*(unsigned int *)sprite->sprite_addr >> 24 != 0xFF)
			*(int *)print_addr = *(int *)sprite->sprite_addr;
		if (sprite->next_step_h >= TEX_PRECISION)
		{
			sprite->next_step_h -= TEX_PRECISION;
			sprite->sprite_addr += sprite->step_h + sprite->img->size_line;
		}
		else
			sprite->sprite_addr += sprite->step_h;
		sprite->next_step_h += sprite->step_precision;
		print_addr += game->scene.size_line;
		i++;
	}
}

void	ft_draw_sgl_sprite(t_game *game, t_sprite *sprite)
{
	char	*obj_addr;

	ft_init_sprite_info(game, sprite);
	// Can't decide between two layers and one only
	obj_addr = game->scene.img_addr + (sprite->ray_index * 4);
	while (sprite->tex_pos_x <= 1 && sprite->ray_index < game->res.x)
	{
		if (sprite->ray_index >= 0 &&
			game->rays[sprite->ray_index].dist > sprite->dist)
		{
			sprite->sprite_addr = sprite->img->img_addr
				+ (int)(sprite->img->width * sprite->tex_pos_x) * 4;
			if (sprite->height > game->res.y)
			{
				sprite->sprite_addr += sprite->skipped_pix;
				sprite->next_step_h = sprite->init_next_step_h;
			}
			else
				sprite->next_step_h = sprite->step_precision;
			ft_draw_sprite_line(game, sprite, obj_addr);
		}
		obj_addr += 4;
		sprite->ray_index++;
		sprite->tex_pos_x += sprite->step_x;
	}
}

void	ft_draw_sprites(t_game *game)
{
	// t_list		*curr_s;

	// // Needed if obj img is implemented
	// // ft_draw_rect(&game->obj, (t_size){x : 0, y : 0}, game->res, 0xFF000000);
	// ft_list_sort(game->sprites, ft_cmp_sprites);
	// curr_s = *game->sprites;
	// while (curr_s)
	// {
	// 	ft_draw_sgl_sprite(game, (t_sprite *)curr_s->content);
	// 	curr_s = curr_s->next;
	// }
}