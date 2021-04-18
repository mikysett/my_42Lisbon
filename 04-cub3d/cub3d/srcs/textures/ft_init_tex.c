/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 10:04:07 by msessa            #+#    #+#             */
/*   Updated: 2021/04/15 10:56:35 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static void	ft_init_sky_tex(t_game *game)
{
	t_map_par	*sky_par;
	t_img_data	*sky;
	t_sky_info	*info;

	sky = &game->sky_tex;
	sky->img_ref = 0;
	info = &game->sky_info;
	sky_par = ft_get_map_param(game->map->map_params, skybox_tex);
	if (sky_par)
	{
		sky->img_ref = mlx_xpm_file_to_image(game->mlx,
			sky_par->val.texture,
			&(sky->width), &(sky->height));
		if (!sky->img_ref)
			return ;
		sky->img_addr = mlx_get_data_addr(sky->img_ref,
			&(sky->bits_pix),
			&(sky->size_line), &(sky->endian));
		info->height = game->res.y / 2;
		info->step_h_float = (double)sky->height / info->height;
		info->step_h = sky->size_line * (int)info->step_h_float;
		info->step_precision = (info->step_h_float - (int)info->step_h_float)
			* TEX_PRECISION;
	}
}

static bool	ft_save_tex(void *mlx, t_img_data *tex, char *tex_path)
{
	tex->img_ref = mlx_xpm_file_to_image(mlx,
		tex_path, &(tex->width), &(tex->height));
	if (!tex->img_ref)
		return (false);
	tex->img_addr = mlx_get_data_addr(tex->img_ref,
		&(tex->bits_pix), &(tex->size_line), &(tex->endian));
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
		if (!tex_sel && (i == trap_tex || i == heal_tex || i == skybox_tex))
		{
			i++;
			continue ;
		}
		if (!ft_save_tex(game->mlx, &game->tex[i], tex_sel->val.texture))
			return (false);
		i++;
	}
	ft_init_sky_tex(game);
	return (true);
}
