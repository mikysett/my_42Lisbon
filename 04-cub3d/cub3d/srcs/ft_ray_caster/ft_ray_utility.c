/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:46:54 by msessa            #+#    #+#             */
/*   Updated: 2021/04/08 16:24:53 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

bool	ft_wall_front_x(t_ray *ray)
{
	if (ray->neg_step_x)
	{
		ray->pos.x = (int)ray->pos.x + 1;
		ray->color = 0xFFAA0000;
	}
	else
	{
		ray->color = 0xFFAA0000;
	}
	return (true);
}

bool	ft_wall_front_y(t_ray *ray)
{
	if (ray->neg_step_y)
	{
		ray->pos.y = ray->pos.y + 1;
		ray->color = 0xFFFFFFFF;
	}
	else
	{
		ray->color = 0xFFFFFFFF;
	}
	return (true);
}