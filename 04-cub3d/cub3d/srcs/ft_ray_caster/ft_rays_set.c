/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:19:20 by msessa            #+#    #+#             */
/*   Updated: 2021/04/16 18:49:08 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

double		ft_normalize_angle(double angle)
{
	if (angle < 0)
		return (FULL_CIRCLE + angle);
	else if (angle >= FULL_CIRCLE)
		return (angle - FULL_CIRCLE);
	return (angle);
}

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
	ray->diff_x = ray_pos.x - p_pos.x;
	ray->diff_y = ray_pos.y - p_pos.y;
	if (fabs(ray->diff_x) > fabs(ray->diff_y))
		ft_ray_cast_x(game, map_grid, ray, p_pos);
	else
		ft_ray_cast_y(game, map_grid, ray, p_pos);
}

void	ft_rays_set(t_game *game, t_ray *rays,
	const int res_x, const double rays_step)
{
	int			i;
	t_size_f	p_pos;
	double		dir_sel;

	p_pos = ft_get_float_pos(game->player->pos, game->player->cell_pos);
	dir_sel = ft_normalize_angle(game->player->dir + game->rays_info.half_fov);
	i = 0;
	// To test
	// printf("\np_dir: %f\n", game->player->dir);
	while (i < res_x)
	{
		// To test
		// printf("angle %4d: %f | ", i, dir_sel);
		// if ((i + 1) % 7 == 0)
		// 	printf("\n");
		rays[i].index = i;
		rays[i].dir = dir_sel;
		rays[i].pos.x = p_pos.x + cos(dir_sel);
		rays[i].pos.y = p_pos.y - sin(dir_sel);
		ft_ray_cast(game, game->map->map_grid, (rays + i), p_pos, rays[i].pos);
		dir_sel = ft_normalize_angle(dir_sel - rays_step);
		i++;
	}
}