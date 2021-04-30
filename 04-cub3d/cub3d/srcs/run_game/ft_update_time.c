/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:45:32 by msessa            #+#    #+#             */
/*   Updated: 2021/04/28 15:42:38 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_update_time(t_game *game)
{
	game->delta_time = 1.0 / 24;
}

void	ft_init_time(t_game *game)
{
	game->delta_time = 1.0 / 24;
	game->settings[show_fps] = false;
}

void	ft_print_fps(t_game *game)
{
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFF0000,
		"FPS: TIME TRACKING NOT SET");
}
