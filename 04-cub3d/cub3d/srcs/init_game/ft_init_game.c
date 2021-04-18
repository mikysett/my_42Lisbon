/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:01:47 by msessa            #+#    #+#             */
/*   Updated: 2021/04/18 17:59:06 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_basic_settings(t_game *game, t_map *map)
{
	game->map = map;
	game->mini_map.size.x = MINI_MAP_WIDTH;
	game->mini_map.size.y = MINI_MAP_HEIGHT;
	game->mini_map.cell_size = MINI_MAP_CELL_SIZE;
	game->mm_img.img_ref = 0;
	game->rays = 0;
	game->sprites = malloc(sizeof(t_list *));
	if (!game->sprites)
	{
		ft_mlx_error(err_sprite);
		exit(EXIT_FAILURE);
	}
	game->sprites = 0;
	game->settings[show_minimap] = true;
	game->settings[show_fps] = true;
	gettimeofday(&(game->new_time), 0);
	game->old_time = game->new_time;
	game->player = ft_ply_init(&(map->player));
}

void	ft_init_layers(t_game *game)
{
	const t_size	pos = {x : 0, y : 0};
	game->win = mlx_new_window(game->mlx, game->res.x, game->res.y, "cub3D");
	game->bg.img_ref = mlx_new_image(game->mlx, game->res.x, game->res.y);
	game->bg.img_addr = mlx_get_data_addr(game->bg.img_ref,
		&game->bg.bits_pix, &game->bg.size_line, &game->bg.endian);
	ft_draw_rect(&game->bg, pos, game->res, 0x00000000);
	game->scene.img_ref = mlx_new_image(game->mlx, game->res.x, game->res.y);
	game->scene.img_addr = mlx_get_data_addr(game->scene.img_ref,
		&game->scene.bits_pix, &game->scene.size_line, &game->scene.endian);
	game->obj.img_ref = mlx_new_image(game->mlx, game->res.x, game->res.y);
	game->obj.img_addr = mlx_get_data_addr(game->obj.img_ref,
		&game->obj.bits_pix, &game->obj.size_line, &game->obj.endian);
}

bool	ft_init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (false);
	game->res = ft_init_res(game, game->map->map_params);
	if (!ft_rays_init(game, game->res.x))
		return (false);
	ft_init_layers(game);
	ft_init_bg(game);
	ft_mm_init_img(game);
	game->mm_pos = ft_mm_set_pos(game->res, game->mini_map.size);
	ft_lifeb_init_img(game);
	// Not working on mac
	// mlx_mouse_hide(game->mlx, game->win);
	return (true);
}

bool	ft_init_game(t_game *game, t_map *map)
{

	ft_basic_settings(game, map);
	if (!ft_init_graphics(game))
	{
		ft_mlx_error(err_mlx);
		return (false);
	}
	if (!ft_init_tex(game) || !ft_init_sprites(game))
	{
		ft_mlx_error(err_tex);
		return (false);
	}
	return (true);
}