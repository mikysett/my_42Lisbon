/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:15:26 by msessa            #+#    #+#             */
/*   Updated: 2021/04/28 15:47:57 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static void	ft_init_bmp_info(t_game *game, t_bmp_info *bmp)
{
	bmp->identifier[0] = 'B';
	bmp->identifier[1] = 'M';
	bmp->file_size = 108 + 14 + bmp->img_size * 4;
	bmp->unused_bytes = 0;
	bmp->pix_array_offset = 108 + 14;
	bmp->dib_header_size = 108;
	bmp->img_width = game->res.x;
	bmp->img_height = game->res.y;
	bmp->nb_color_planes = 1;
	bmp->bits_per_pixel = 32;
	bmp->compression = 3;
	bmp->bmp_array_size = bmp->img_size * 4;
	bmp->x_resolution = 2835;
	bmp->y_resolution = 2835;
	bmp->clrs_palette = 0;
	bmp->important_clrs = 0;
	bmp->red_mask = 0x00FF0000;
	bmp->green_mask = 0x0000FF00;
	bmp->blue_mask = 0x000000FF;
	bmp->alpha_mask = 0x00000000;
	bmp->color_space = 0x206E6957;
	bmp->size_line_int = game->scene.size_line / 4;
	bmp->scene_addr = (int *)(game->scene.img_addr);
	bmp->obj_addr = (int *)(game->obj.img_addr);
}

static void	ft_init_bmp_body(t_game *game, t_bmp_info *bmp)
{
	int	i;
	int	line_mirror;

	i = 0;
	line_mirror = (game->res.y - 1) * bmp->size_line_int;
	while (line_mirror >= 0)
	{
		if ((*bmp->obj_addr & 0xFF000000) != 0xFF000000)
			bmp->bmp_arr[i + line_mirror] = *bmp->obj_addr;
		else
			bmp->bmp_arr[i + line_mirror] = *bmp->scene_addr;
		bmp->scene_addr++;
		bmp->obj_addr++;
		i++;
		if (i == bmp->size_line_int)
		{
			i = 0;
			line_mirror -= bmp->size_line_int;
		}
	}
}

static bool	ft_init_bmp_arr(t_game *game, t_bmp_info *bmp)
{
	bmp->img_size = game->res.x * game->res.y;
	bmp->bmp_arr = malloc(sizeof(int) * bmp->img_size);
	if (!bmp->bmp_arr)
		return (false);
	return (true);
}

void	ft_save_bmp(t_game *game)
{
	t_bmp_info	bmp;
	int			fd;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (!fd || !ft_init_bmp_arr(game, &bmp))
	{
		ft_mlx_error(err_save_bmp);
		return ;
	}
	ft_init_bmp_info(game, &bmp);
	ft_write_bmp_header(fd, &bmp);
	ft_write_dib_header(fd, &bmp);
	ft_init_bmp_body(game, &bmp);
	write(fd, bmp.bmp_arr, bmp.img_size * 4);
	close(fd);
	free(bmp.bmp_arr);
	ft_exit_game(0, (void *)game);
}
