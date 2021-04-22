/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_time_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:45:32 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 17:45:51 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_update_time(t_game *game)
{
	game->delta_time = (game->new_time.tv_sec
			+ (game->new_time.tv_usec / 1000000.0))
		- (game->old_time.tv_sec + (game->old_time.tv_usec / 1000000.0));
	game->old_time = game->new_time;
	gettimeofday(&(game->new_time), 0);
}

void	ft_init_time(t_game *game)
{
	gettimeofday(&game->new_time, 0);
}

void	ft_print_fps(t_game *game)
{
	char	*fps;

	if (game->delta_time < 0.001)
		fps = ft_strdup("> 1000");
	else
		fps = ft_itoa(1.0 / game->delta_time);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFF0000, "FPS: ");
	mlx_string_put(game->mlx, game->win, 60, 20, 0xFFFF0000, fps);
	free(fps);
}
