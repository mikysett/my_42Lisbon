/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lifebar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:45:35 by msessa            #+#    #+#             */
/*   Updated: 2021/04/14 19:20:08 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_lifeb_init_img(t_game *game)
{
	t_mini_map	*mm;
	t_img_data	*img;

	mm = &(game->mini_map);
	img = &(game->lb.img);
	img->img_ref = mlx_new_image(game->mlx, mm->size.x, LIFEBAR_HEIGHT);
	img->img_addr = mlx_get_data_addr(img->img_ref, &(img->bits_pix),
		&(img->size_line), &(img->endian));
	game->lb.pos.x = game->mm_pos.x;
	game->lb.pos.y = game->mm_pos.y - LIFEBAR_HEIGHT - 5;
	game->lb.size.x = game->mini_map.size.x;
	game->lb.size.y = LIFEBAR_HEIGHT;
}

void	ft_lifeb_update(t_game *game)
{
	int	life_rect;
	int	life_clr;

	if (game->player->life <= 30)
		life_clr = CLR_LIFE_BAD;
	else if (game->player->life <= 70)
		life_clr = CLR_LIFE_MID;
	else
		life_clr = CLR_LIFE_OK;
	life_rect = game->player->life / 100.0 * (game->lb.size.x - 8);
	ft_draw_rect(&game->lb.img, (t_size) {x : 0, y : 0}, game->lb.size, CLR_BG);
	ft_draw_rect(&game->lb.img,
		(t_size) {x : 4, y : 4},
		(t_size) {x : life_rect, y : game->lb.size.y - 8},
		life_clr);
}