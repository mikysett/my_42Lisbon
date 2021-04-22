/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:53:08 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 19:05:21 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static int	ft_count_sprites(t_map_el **map_grid, t_size size)
{
	int	nb_sprites;
	int	x;
	int	y;

	nb_sprites = 0;
	x = 0;
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			if (map_grid[x][y].type >= item && map_grid[x][y].type <= trap)
				nb_sprites++;
			y++;
		}
		x++;
	}
	return (nb_sprites);
}

static void	ft_preset_sprites(t_game *game, t_sprite *sprite_sel,
	t_map_el **map_grid, t_size size)
{
	int			x;
	int			y;

	x = 0;
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			if (map_grid[x][y].type >= item && map_grid[x][y].type <= trap)
			{
				sprite_sel->is_picked = false;
				sprite_sel->in_fov = false;
				sprite_sel->pos = (t_size){.x = x, .y = y};
				sprite_sel->f_pos.x = x + 0.5;
				sprite_sel->f_pos.y = y + 0.5;
				sprite_sel->img = &game->tex[map_grid[x][y].type];
				sprite_sel++;
			}
			y++;
		}
		x++;
	}
}

bool	ft_init_sprites(t_game *game)
{
	game->nb_sprites = ft_count_sprites(game->map->map_grid,
			game->map->map_size);
	if (!game->nb_sprites)
		return (true);
	game->sprites = malloc(sizeof(t_sprite) * game->nb_sprites);
	if (!game->sprites)
		return (false);
	ft_preset_sprites(game, game->sprites,
		game->map->map_grid, game->map->map_size);
	return (true);
}
