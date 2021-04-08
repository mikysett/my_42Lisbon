/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_set_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:45:54 by msessa            #+#    #+#             */
/*   Updated: 2021/04/08 01:52:57 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static void	ft_set_sidewall_x_neg(t_ray *ray)
{
	if (ray->neg_step_y)
	{
		ray->intersec.y = (int)(ray->pos.y) + 1 - ray->pos.y;
		ray->intersec.x = ray->intersec.y / -tan(ray->dir);
	}
	else
	{
		ray->intersec.y = ray->pos.y - (int)(ray->pos.y);
		ray->intersec.x = ray->intersec.y / tan(ray->dir);
	}
	if (ray->intersec.x > 0 && ray->intersec.x < 1)
	{
		ray->pos.x = ray->pos.x + ray->intersec.x;
		ray->color = 0xFFFFFFFF;
	}
	else
		ft_wall_front_x(ray);
}

static void	ft_set_sidewall_x_pos(t_ray *ray)
{
	if (ray->neg_step_y)
	{
		ray->intersec.y = (int)(ray->pos.y) + 1 - ray->pos.y;
		ray->intersec.x = ray->intersec.y / tan(ray->dir);
	}
	else
	{
		ray->intersec.y = ray->pos.y - (int)(ray->pos.y);
		ray->intersec.x = ray->intersec.y / -tan(ray->dir);
	}
	ray->pos.x = ray->pos.x - ray->intersec.x;
	ray->color = 0xFFFFFFFF;
}

static void	ft_ray_cast_x_neg(t_map_el **map_grid, t_ray *ray,
	t_size_f p_pos)
{
	double	last_ray_pos_y;

	ray->pos.x = (int)p_pos.x;
	ray->pos.y = p_pos.y + tan(ray->dir) * (p_pos.x - (int)p_pos.x);
	last_ray_pos_y = ray->pos.y;
	while (map_grid[(int)ray->pos.x][(int)ray->pos.y].type != wall)
	{
		last_ray_pos_y = ray->pos.y;
		ray->pos.x -= 1;
		ray->pos.y += ray->y_incr;
		if ((int)last_ray_pos_y != (int)ray->pos.y
			&& map_grid[(int)ray->pos.x][(int)last_ray_pos_y].type == wall)
		{
			ft_wall_front_x(ray);
			return ;
		}
	}
	if ((int)last_ray_pos_y != (int)ray->pos.y
		&& map_grid[(int)ray->pos.x][(int)last_ray_pos_y].type == wall)
		ft_wall_front_x(ray);
	else
		ft_set_sidewall_x_neg(ray);
}

static void	ft_ray_cast_x_pos(t_map_el **map_grid, t_ray *ray,
	t_size_f p_pos)
{
	double	last_ray_pos_y;

	last_ray_pos_y = p_pos.y;
	ray->pos.x = (int)p_pos.x + 1;
	ray->pos.y = p_pos.y - tan(ray->dir) * (ray->pos.x - p_pos.x);
	while (map_grid[(int)ray->pos.x][(int)ray->pos.y].type != wall)
	{
		if (((int)last_ray_pos_y != (int)ray->pos.y
			&& map_grid[(int)ray->pos.x - 1][(int)ray->pos.y].type == wall))
		{
			ft_set_sidewall_x_pos(ray);
			return ;
		}
		last_ray_pos_y = ray->pos.y;
		ray->pos.x += 1;
		ray->pos.y += ray->y_incr;
	}
	if (((int)last_ray_pos_y != (int)ray->pos.y
		&& map_grid[(int)ray->pos.x - 1][(int)ray->pos.y].type == wall))
		ft_set_sidewall_x_pos(ray);
	else
		ft_wall_front_x(ray);
}

void	ft_ray_cast_x(t_game *game, t_map_el **map_grid, t_ray *ray,
	t_size_f p_pos)
{
	ray->step = fabs(ray->diff_x);
	ray->slope = 'x';
	if (ray->diff_x < 0)
		ray->neg_step_x = true;
	else
		ray->neg_step_x = false;
	if (ray->diff_y < 0)
		ray->neg_step_y = true;
	else
		ray->neg_step_y = false;
	ray->y_incr = ray->diff_y / ray->step;
	if (ray->neg_step_x)
		ft_ray_cast_x_neg(map_grid, ray, p_pos);
	else
		ft_ray_cast_x_pos(map_grid, ray, p_pos);
	ray->dist = ((p_pos.x - ray->pos.x) / sin(DEGREES_270 - ray->dir))
		* sin(game->player->dir + DEGREES_90 - ray->dir);
}