/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:19:20 by msessa            #+#    #+#             */
/*   Updated: 2021/04/07 21:35:57 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

t_size_f	ft_get_float_pos(t_size pos, t_size cell_pos)
{
	t_size_f	f_pos;

	f_pos.x = pos.x + cell_pos.x / (double)NB_CELL_POS;
	f_pos.y = pos.y + cell_pos.y / (double)NB_CELL_POS;
	return (f_pos);
}

void	ft_ray_cast(t_game *game, t_map_el **map_grid, t_ray *ray,
	t_size_f p_pos, t_size_f ray_pos)
{
	t_size_f	intersec;

	ray->diff_x = ray_pos.x - p_pos.x;
	ray->diff_y = ray_pos.y - p_pos.y;
	if (fabs(ray->diff_x) > fabs(ray->diff_y))
	{
		ft_ray_cast_x(game, map_grid, ray, p_pos);
		return ;
		ray->step = fabs(ray->diff_x);
		ray->slope = 'x';
	}
	else
	{
		ft_ray_cast_y(game, map_grid, ray, p_pos);
		return ;
		ray->step = fabs(ray->diff_y);
		ray->slope = 'y';
	}
	if (ray->diff_x < 0)
		ray->neg_step_x = true;
	else
		ray->neg_step_x = false;
	if (ray->diff_y < 0)
		ray->neg_step_y = true;
	else
		ray->neg_step_y = false;
	ray->x_incr = ray->diff_x / ray->step;
	ray->y_incr = ray->diff_y / ray->step;
	if (ray->slope == 'x' && ray->neg_step_x && !ray->neg_step_y)
	{
		ray_pos.x = (int)p_pos.x;
		ray_pos.y = p_pos.y + tan(ray->dir) * (p_pos.x - (int)p_pos.x);
	}
	else
	{
		ray_pos.x = p_pos.x + ray->x_incr;
		ray_pos.y = p_pos.y + ray->y_incr;
	}
	while (1)
	{
		if (map_grid[(int)ray_pos.x][(int)ray_pos.y].type == wall)
		{
			if (ray->slope == 'x')
			{
				ray->dist = fabs(ray_pos.x - p_pos.x);
				if (ray->neg_step_y)
				{
					// To be implemented
					// Ray going up
					ray->dist = 1000;
				}
				else
				{
					if ((int)ray_pos.x == p_pos.x)
						intersec.y = ray_pos.y - p_pos.y;
					else
						intersec.y = ray_pos.y - (int)(ray_pos.y);
					intersec.x = (intersec.y / tan(ray->dir));
					if (ray->neg_step_x)
					{
						if ((int)(ray_pos.x + intersec.x) == (int)ray_pos.x
							&& map_grid[(int)ray_pos.x][(int)ray_pos.y - 1].type != wall)
						{
							ray->pos.x = ray_pos.x + intersec.x;
							ray->color = 0xFFFFFFFF;
						}
						else
						{
							ray->pos.x = (int)ray_pos.x + 1;
							ray->pos.y = ray_pos.y;
							ray->color = 0xFFAA0000;
						}
					}
					else
					{
						// To be implemented
						// Ray going right
					}
					// printf("ray->dir: %f sin: %f\n", ft_rad_to_deg(ray->dir), sin(FULL_CIRCLE - ray->dir));

					ray->dist = ((p_pos.x - ray->pos.x) / sin(FULL_CIRCLE - DEGREES_90 - ray->dir)) * sin(game->player->dir + DEGREES_90 - ray->dir);
					if (ray->dist < 0)
					{
						ray->dist = 0;
						ray->color = 0xFF00FF00;
					}
				}
			}
			else
			{
				// To be implemented
				// slope == y
			}
			return ;
		}
		ray_pos.x += ray->x_incr;
		ray_pos.y += ray->y_incr;
	}

}

void	ft_rays_set(t_game *game, t_ray *rays,
	const int res_x, const double rays_step)
{
	int			i;
	t_size_f	p_pos;
	double		dir_sel;

	p_pos = ft_get_float_pos(game->player->pos, game->player->cell_pos);
	// To test
	// printf("Player float pos: - x: %.5f, y: %.5f", p_pos.x, p_pos.y);
	dir_sel = game->player->dir + game->rays_info.half_fov;
	i = 0;
	printf("start\n");
	while (i < res_x)
	{
		rays[i].dir = dir_sel;
		rays[i].pos.x = p_pos.x + cos(dir_sel);
		rays[i].pos.y = p_pos.y - sin(dir_sel);
		ft_ray_cast(game, game->map->map_grid, (rays + i), p_pos, rays[i].pos);
		dir_sel -= rays_step;
		i++;
	}
}