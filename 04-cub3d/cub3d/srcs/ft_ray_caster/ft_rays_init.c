/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:19:20 by msessa            #+#    #+#             */
/*   Updated: 2021/04/03 12:58:26 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

bool	ft_rays_init(t_game *game, int res_x)
{
	game->rays = malloc(sizeof(t_ray) * game->res.x);
	if (!game->rays)
		return (false);
	game->rays_info.fov = FOV_66;
	game->rays_info.half_fov = game->rays_info.fov / 2.0;
	game->rays_info.step = game->rays_info.fov / res_x;
	return (true);
}