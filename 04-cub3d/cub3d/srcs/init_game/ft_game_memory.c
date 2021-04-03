/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:55:49 by msessa            #+#    #+#             */
/*   Updated: 2021/04/02 20:29:07 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_free_game(t_game *game)
{
	ft_free_map(game->map);

	// to test
	if (game->win)
	{
		// textures needs to be improved
		if (game->text)
			mlx_destroy_image(game->mlx, game->text);
		if (game->mm_img.img_ref)
			mlx_destroy_image(game->mlx, game->mm_img.img_ref);
		mlx_destroy_window(game->mlx, game->win);
		if (game->rays)
			free(game->rays);
	}
	// free(game->mlx);
}

int	ft_exit_game(int key, void *game)
{
	(void)key;
	ft_free_game((t_game *)game);
	exit(EXIT_SUCCESS);
	return (1);
}