/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:10:10 by msessa            #+#    #+#             */
/*   Updated: 2021/04/17 20:21:20 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TESTS_H
# define FT_TESTS_H

void	ft_print_split(char **str);
void	ft_print_params_set(bool *param_set);
void	ft_print_map_grid(t_map *map);
double	ft_deg_to_rad(double deg);
double	ft_rad_to_deg(double rad);
void	ft_print_rays(t_ray *rays, const int res_x);
void	ft_print_sprites_info(t_sprite *sprites, int nb_sprites);

#endif