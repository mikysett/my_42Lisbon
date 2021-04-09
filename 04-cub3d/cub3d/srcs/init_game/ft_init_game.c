/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:01:47 by msessa            #+#    #+#             */
/*   Updated: 2021/04/09 20:02:54 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

t_map_par	*ft_get_map_param(t_list **params, t_map_p_types type_sel)
{
	t_list	*head;

	head = *params;
	while (head)
	{
		if (((t_map_par *)(head->content))->type == type_sel)
			return ((t_map_par *)(head->content));
		head = head->next;
	}
	return (0);
}

void	ft_mm_init_img(t_game *game)
{
	t_mini_map	*mm;
	t_img_data	*img;

	mm = &(game->mini_map);
	img = &(game->mm_img);
	img->img_ref = mlx_new_image(game->mlx, mm->size.x, mm->size.y);
	img->img_addr = mlx_get_data_addr(img->img_ref, &(img->bits_pix),
		&(img->size_line), &(img->endian));
}

t_size	ft_init_res(t_list **map_params)
{
	t_map_par	*res;

	res = ft_get_map_param(map_params, resolution);
	if (res->val.res.x > MAX_RES_X)
		res->val.res.x = MAX_RES_X;
	if (res->val.res.y > MAX_RES_Y)
		res->val.res.y = MAX_RES_Y;
	return (res->val.res);
}

t_size	ft_mm_set_pos(t_size win_size, t_size mm_size)
{
	t_size	mm_pos;

	mm_pos.x = MINI_MAP_PADDING;
	mm_pos.y = win_size.y - mm_size.y - MINI_MAP_PADDING;
	return (mm_pos);
}

t_player	*ft_ply_init(t_player *player)
{
	int	i;

	i = 0;
	player->last_pos = (t_size){x : 0, y : 0};
	player->last_cell_pos = (t_size){x : 0, y : 0};
	player->rotating[r_left] = false;
	player->rotating[r_right] = false;
	while (i < NB_DIRECTIONS)
	{
		player->moving[i] = false;
		i++;
	}
	return (player);
}

void	ft_basic_settings(t_game *game, t_map *map)
{
	game->map = map;
	game->mini_map.size.x = MINI_MAP_WIDTH;
	game->mini_map.size.y = MINI_MAP_HEIGHT;
	game->mini_map.cell_size = MINI_MAP_CELL_SIZE;
	game->mm_img.img_ref = 0;
	game->rays = 0;
	game->settings[show_minimap] = true;
	game->settings[show_fps] = true;
	gettimeofday(&(game->new_time), 0);
	game->old_time = game->new_time;
	game->player = ft_ply_init(&(map->player));
}

bool	ft_init_graphics(t_game *game)
{
	game->tex_size = TEX_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (false);
	game->res = ft_init_res(game->map->map_params);
	if (!ft_rays_init(game, game->res.x))
		return (false);
	game->win = mlx_new_window(game->mlx, game->res.x, game->res.y, "cub3D");
	game->scene.img_ref = mlx_new_image(game->mlx, game->res.x, game->res.y);
	game->scene.img_addr = mlx_get_data_addr(game->scene.img_ref,
		&(game->scene.bits_pix), &(game->scene.size_line), &(game->scene.endian));
	ft_mm_init_img(game);
	game->mm_pos = ft_mm_set_pos(game->res, game->mini_map.size);
	return (true);
}

bool	ft_init_tex(t_game *game)
{
	t_map_par	*tex_sel;
	t_img_data	*tex;
	int			i;

	tex = game->tex;
	i = 0;
	while(i < NB_TEX)
		tex[i++].img_ref = 0;
	i = 0;
	while (i < NB_TEX)
	{
		tex_sel = ft_get_map_param(game->map->map_params, i);
		game->tex[i].img_ref = mlx_xpm_file_to_image(game->mlx,
			tex_sel->val.texture,
			&(game->tex[i].width), &(game->tex[i].height));
		if (!game->tex[i].img_ref)
			return (false);
		game->tex[i].img_addr = mlx_get_data_addr(game->tex[i].img_ref,
			&(game->tex[i].bits_pix),
			&(game->tex[i].size_line), &(game->tex[i].endian));
		i++;
	}
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
	// To load textures, still to be developped
	if (!ft_init_tex(game))
	{
		ft_mlx_error(err_tex);
		return (false);
	}
	return (true);
}