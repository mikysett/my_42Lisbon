/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:21:10 by msessa            #+#    #+#             */
/*   Updated: 2021/04/17 21:20:03 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_set_sprites(t_game *game)
{
	t_ray		*first_ray;
	t_ray		*last_ray;
	t_sprite	*sprite_sel;
	int			i;

	// calculate angle for visibility
	first_ray = game->rays;
	last_ray = &game->rays[game->res.x - 1];
	i = 0;
	sprite_sel = game->sprites;
	while (i < game->nb_sprites)
	{
		if (first_ray->slope == 'x')
		{
			if (!first_ray->neg_step_x && sprite_sel->f_pos.y )
		}
		sprite_sel++;
		i++;
	}

	// calculate distance

	// go for it!
}