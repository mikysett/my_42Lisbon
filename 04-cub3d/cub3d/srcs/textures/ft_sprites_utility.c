/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_utility.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:00:28 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 19:01:12 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_sort_sprites(t_game *game)
{
	int			i;
	int			j;
	t_sprite	s_buf;

	i = 0;
	while (i < game->nb_sprites)
	{
		if (!game->sprites[i].in_fov)
			return ;
		j = i + 1;
		while (j < game->nb_sprites)
		{
			if (!game->sprites[j].in_fov)
				break ;
			if (game->sprites[i].dist < game->sprites[j].dist)
			{
				s_buf = game->sprites[j];
				game->sprites[j] = game->sprites[i];
				game->sprites[i] = s_buf;
			}
			j++;
		}
		i++;
	}
}
