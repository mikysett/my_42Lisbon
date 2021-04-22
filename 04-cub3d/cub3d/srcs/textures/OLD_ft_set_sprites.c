/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLD_ft_set_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:21:10 by msessa            #+#    #+#             */
/*   Updated: 2021/04/21 19:12:49 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

// static void	ft_sprite_x(t_game *game, t_ray *ray,
// 	t_sprite *sprite, t_size_f p_pos)
// {
// 	if (ray->neg_step_x)
// 	{
// 		sprite->f_pos.x = (int)ray->pos.x + 1;
// 		sprite->f_pos.y -= ray->y_incr;
// 		sprite->tex_pos_x = 1 - (sprite->f_pos.y - (int)sprite->f_pos.y);
// 	}
// 	else
// 		sprite->tex_pos_x = sprite->f_pos.y - (int)sprite->f_pos.y;
// 	sprite->dist = ((p_pos.x - sprite->f_pos.x) / sin(DEG_270 - ray->dir))
// 		* sin(game->player->dir + DEG_90 - ray->dir);
// }

// static void	ft_sprite_x(t_game *game, t_ray *ray,
// 	t_sprite *sprite, t_size_f p_pos)
// {
// 	double	correction;
// 	double	correction_rad;

// 	if (ray->neg_step_x)
// 	{
// 		sprite->f_pos.x = (int)ray->pos.x + 1;
// 		sprite->f_pos.y -= ray->y_incr;
// 		sprite->tex_pos_x = 1 - (sprite->f_pos.y - (int)sprite->f_pos.y);
// 		sprite->dist = ((p_pos.x - sprite->f_pos.x) / sin(DEG_270 - ray->dir))
// 			* sin(game->player->dir + DEG_90 - ray->dir);
// 	}
// 	else
// 	{
// 		if (game->player->dir < DEG_90)
// 			correction_rad = game->player->dir;
// 		else
// 			correction_rad = -(game->player->dir - FULL_CIRCLE);
// 		correction = tan(correction_rad) * 0.5;

// 		sprite->f_pos.x = sprite->f_pos.x + 0.5 + correction;
// 		sprite->ray_index += (int)(sin(correction_rad) * (0.5 + correction));
// 		// if (sprite->ray_index < 0)
// 		// {
// 		// 	sprite->dist = INT_MAX;
// 		// 	sprite->ray_index = 0;
// 		// 	return ;
// 		// }

// 		// sprite->f_pos.y -= game->rays[sprite->ray_index].y_incr;
// 		sprite->tex_pos_x = sprite->f_pos.y - (int)sprite->f_pos.y;
// 		sprite->dist = ((p_pos.x - sprite->f_pos.x) / sin(DEG_270 - game->rays[sprite->ray_index].dir))
// 			* sin(game->player->dir + DEG_90 - game->rays[sprite->ray_index].dir);
// 		// printf("ray index: %d\n", sprite->ray_index);
// 		// printf("tex_pos_x: %f\n", sprite->tex_pos_x);
// 		// printf("correction_rad: %f\n", correction_rad);
// 		// printf("correction: %f\n", correction);
// 		// printf("dist: %f\n\n", sprite->dist);
// 	}
// 	// sprite->dist = 1000000;
// }

// 		// if (game->player->dir < DEG_90)
// 		// 	correction_rad = DEG_90 - game->player->dir;
// 		// else
// 		// 	correction_rad = DEG_90 - (FULL_CIRCLE - game->player->dir);



// // static void	ft_sprite_y(t_game *game, t_ray *ray,
// // 	t_sprite *sprite, t_size_f p_pos)
// // {
// // 	if (ray->neg_step_y)
// // 	{
// // 		sprite->f_pos.y = sprite->f_pos.y + 1;
// // 		sprite->f_pos.x -= ray->x_incr;
// // 		sprite->tex_pos_x = sprite->f_pos.x - (int)sprite->f_pos.x;
// // 	}
// // 	else
// // 		sprite->tex_pos_x = 1 - (sprite->f_pos.x - (int)sprite->f_pos.x);
// // 	sprite->dist = cos(ray->dir - game->player->dir)
// // 		* ((p_pos.y - sprite->f_pos.y) / sin(DEG_180 - ray->dir));
// // }



// static void	ft_sprite_y(t_game *game, t_ray *ray,
// 	t_sprite *sprite, t_size_f p_pos)
// {
// 	double	correction;
// 	double	correction_rad;

// 	if (ray->neg_step_y)
// 	{
// 		correction_rad = DEG_180 - (game->player->dir + DEG_90);
// 		correction = tan(correction_rad) * 0.5;

// 		sprite->f_pos.y = sprite->f_pos.y + 1.5 - correction;
// 		sprite->ray_index += (int)(sin(correction_rad) * (0.5 + correction));

// 		sprite->f_pos.x -= game->rays[sprite->ray_index].x_incr;
// 		sprite->tex_pos_x = sprite->f_pos.x - (int)sprite->f_pos.x;
// 		sprite->dist = cos(game->rays[sprite->ray_index].dir - game->player->dir)
// 			* ((p_pos.y - sprite->f_pos.y) / sin(DEG_180 - game->rays[sprite->ray_index].dir));
// 	}
// 	else
// 	{
// 		correction_rad = FULL_CIRCLE - game->player->dir - DEG_90;
// 		correction = tan(correction_rad) * 0.5;

// 		sprite->f_pos.y = sprite->f_pos.y + 0.5 + correction;
// 		sprite->ray_index -= (int)(sin(correction_rad) * (0.5 + correction));
// 		// if (sprite->ray_index < 0)
// 		// {
// 		// 	printf("tex pos x before: %f\n", sprite->tex_pos_x);
// 		// 	sprite->tex_pos_x += -(1) * sprite->ray_index;
// 		// 	printf("tex pos x after: %f\n", sprite->tex_pos_x);
// 		// 	sprite->ray_index = 0;
// 		// 	sprite->dist = 0.5;
// 		// }
// 		// else
// 		{
// 			// printf("sprite->ray_index: %d\n", sprite->ray_index);
// 			sprite->tex_pos_x = 1 - (sprite->f_pos.x - (int)sprite->f_pos.x);
// 			sprite->dist = cos(game->rays[sprite->ray_index].dir - game->player->dir)
// 				* ((p_pos.y - sprite->f_pos.y) / sin(DEG_180 - game->rays[sprite->ray_index].dir));

// 		}
// 	}
// }

// void	ft_set_sprite(t_game *game, t_ray *ray, t_map_el *curr_el,
// 	t_size_f p_pos)
// {
// 	t_sprite	*sprite;

// 	sprite = malloc(sizeof(t_sprite));
// 	if (!sprite)
// 	{
// 		ft_mlx_error(err_sprite);
// 		exit(EXIT_FAILURE);
// 	}
// 	curr_el->sprite_done = true;
// 	sprite->img = &game->tex[curr_el->type];
// 	sprite->map_el = curr_el;
// 	sprite->ray_index = ray->index;
// 	sprite->f_pos = ray->pos;
// 	if (fabs(ray->diff_x) > fabs(ray->diff_y))
// 		ft_sprite_x(game, ray, sprite, p_pos);
// 	else
// 		ft_sprite_y(game, ray, sprite, p_pos);
// 	ft_lstadd_front(game->sprites, ft_lstnew(sprite));
// }