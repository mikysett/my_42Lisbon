/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_caster.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:13:56 by msessa            #+#    #+#             */
/*   Updated: 2021/04/09 15:43:28 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAY_CASTER
# define FT_RAY_CASTER

bool	ft_rays_init(t_game *game, int res_x);
void	ft_rays_set(t_game *game, t_ray *rays,
	const int res_x, const double rays_step);


void	ft_ray_cast_x(t_game *game, t_map_el **map_grid, t_ray *ray,
	t_size_f p_pos);
void	ft_ray_cast_y(t_game *game, t_map_el **map_grid, t_ray *ray,
	t_size_f p_pos);
void	ft_wall_front_x(t_ray *ray);
void	ft_wall_front_y(t_ray *ray);

#endif