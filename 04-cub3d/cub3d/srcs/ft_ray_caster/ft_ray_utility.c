/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:46:54 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 17:22:36 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_wall_front_x(t_ray *ray)
{
	if (ray->neg_step_x)
	{
		ray->pos.x = (int)ray->pos.x + 1;
		ray->pos.y -= ray->y_incr;
		ray->tex = tex_wall_w;
		ray->tex_pos = 1 - (ray->pos.y - (int)ray->pos.y);
	}
	else
	{
		ray->tex = tex_wall_e;
		ray->tex_pos = ray->pos.y - (int)ray->pos.y;
	}
}

void	ft_wall_front_y(t_ray *ray)
{
	if (ray->neg_step_y)
	{
		ray->pos.x -= ray->x_incr;
		ray->pos.y = ray->pos.y + 1;
		ray->tex = tex_wall_n;
		ray->tex_pos = ray->pos.x - (int)ray->pos.x;
	}
	else
	{
		ray->tex = tex_wall_s;
		ray->tex_pos = 1 - (ray->pos.x - (int)ray->pos.x);
	}
}
