/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_set_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:45:54 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 17:43:30 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static void	ft_set_sidewall_y_neg(t_ray *ray)
{
	if (ray->neg_step_x)
	{
		ray->intersec.x = (int)(ray->pos.x) + 1 - ray->pos.x;
		ray->intersec.y = ray->intersec.x / tan(ray->dir - DEG_90);
		ray->tex = tex_wall_w;
	}
	else
	{
		ray->intersec.x = ray->pos.x - (int)ray->pos.x;
		ray->intersec.y = ray->intersec.x / tan(DEG_90 - ray->dir);
		ray->tex = tex_wall_e;
	}
	if (ray->intersec.y > 0 && ray->intersec.y < 1)
	{
		ray->pos.y = ray->pos.y + ray->intersec.y;
		if (ray->neg_step_x)
			ray->tex_pos = 1 - (ray->pos.y - (int)ray->pos.y);
		else
			ray->tex_pos = ray->pos.y - (int)ray->pos.y;
	}
	else
		ft_wall_front_y(ray);
}

static void	ft_set_sidewall_y_pos(t_ray *ray)
{
	if (ray->neg_step_x)
	{
		ray->intersec.x = (int)(ray->pos.x) + 1 - ray->pos.x;
		ray->intersec.y = ray->intersec.x / tan(DEG_90 - ray->dir);
		ray->pos.y = ray->pos.y - ray->intersec.y;
		ray->tex = tex_wall_w;
		ray->tex_pos = 1 - (ray->pos.y - (int)ray->pos.y);
	}
	else
	{
		ray->intersec.x = ray->pos.x - (int)(ray->pos.x);
		ray->intersec.y = ray->intersec.x / tan(ray->dir - DEG_90);
		ray->pos.y = ray->pos.y - ray->intersec.y;
		ray->tex = tex_wall_e;
		ray->tex_pos = ray->pos.y - (int)ray->pos.y;
	}
}

static void	ft_ray_cast_y_neg(t_map_el **map_grid, t_ray *ray, t_size_f p_pos)
{
	double		last_ray_pos_x;

	ray->pos.y = (int)p_pos.y;
	ray->pos.x = p_pos.x - tan(ray->dir - DEG_90) * (p_pos.y - ray->pos.y);
	last_ray_pos_x = p_pos.x;
	while (map_grid[(int)ray->pos.x][(int)ray->pos.y].type != wall)
	{
		last_ray_pos_x = ray->pos.x;
		ray->pos.y -= 1;
		ray->pos.x += ray->x_incr;
		if ((int)last_ray_pos_x != (int)ray->pos.x
			&& map_grid[(int)last_ray_pos_x][(int)ray->pos.y].type == wall)
		{
			ft_wall_front_y(ray);
			return ;
		}
	}
	ft_set_sidewall_y_neg(ray);
}

static void	ft_ray_cast_y_pos(t_map_el **map_grid, t_ray *ray, t_size_f p_pos)
{
	double		last_ray_pos_x;

	last_ray_pos_x = p_pos.x;
	ray->pos.y = (int)p_pos.y + 1;
	ray->pos.x = p_pos.x + tan(ray->dir - DEG_270) * (ray->pos.y - p_pos.y);
	while (map_grid[(int)ray->pos.x][(int)ray->pos.y].type != wall)
	{
		if ((int)last_ray_pos_x != (int)ray->pos.x
			&& map_grid[(int)ray->pos.x][(int)ray->pos.y - 1].type == wall)
		{
			ft_set_sidewall_y_pos(ray);
			return ;
		}
		last_ray_pos_x = ray->pos.x;
		ray->pos.y += 1;
		ray->pos.x += ray->x_incr;
	}
	if (((int)last_ray_pos_x != (int)ray->pos.x
			&& map_grid[(int)ray->pos.x][(int)ray->pos.y - 1].type == wall))
		ft_set_sidewall_y_pos(ray);
	else
		ft_wall_front_y(ray);
}

void	ft_ray_cast_y(t_game *game, t_map_el **map_grid, t_ray *ray,
	t_size_f p_pos)
{
	ray->step = fabs(ray->diff_y);
	ray->slope = 'y';
	if (ray->diff_y < 0)
		ray->neg_step_y = true;
	else
		ray->neg_step_y = false;
	if (ray->diff_x < 0)
		ray->neg_step_x = true;
	else
		ray->neg_step_x = false;
	ray->x_incr = ray->diff_x / ray->step;
	if (ray->neg_step_y)
		ft_ray_cast_y_neg(map_grid, ray, p_pos);
	else
		ft_ray_cast_y_pos(map_grid, ray, p_pos);
	ray->dist = cos(ray->dir - game->player->dir)
		* ((p_pos.y - ray->pos.y) / sin(DEG_180 - ray->dir));
}
