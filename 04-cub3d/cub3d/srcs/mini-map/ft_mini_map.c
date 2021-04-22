/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:59:46 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 17:25:41 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

t_size	ft_mm_set_pos(t_size win_size, t_size mm_size)
{
	t_size	mm_pos;

	mm_pos.x = MINI_MAP_PADDING;
	mm_pos.y = win_size.y - mm_size.y - MINI_MAP_PADDING;
	return (mm_pos);
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

static void	ft_mm_init(t_player *p, t_mini_map *mm)
{
	double	buf;

	buf = mm->cell_size / (double)NB_CELL_POS;
	mm->cell_offset.x = p->cell_pos.x * buf;
	mm->cell_offset.y = p->cell_pos.y * buf;
	mm->nb_cells.x = mm->size.x / mm->cell_size + 1;
	mm->nb_cells.y = mm->size.y / mm->cell_size + 1;
	mm->first_cell.x = p->pos.x - mm->nb_cells.x / 2;
	mm->first_cell.y = p->pos.y - mm->nb_cells.y / 2;
}

void	*ft_mini_map(t_game *game)
{
	t_mini_map	*mm;

	mm = &game->mini_map;
	ft_mm_init(game->player, mm);
	ft_mm_print(game, game->map, mm, &(game->mm_img));
	return (0);
}
