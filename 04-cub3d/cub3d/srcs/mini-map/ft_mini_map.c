/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:59:46 by msessa            #+#    #+#             */
/*   Updated: 2021/04/01 18:29:36 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"


void	ft_mm_init(t_player *p, t_mini_map *mm)
{
	double	buf;

	buf = mm->cell_size / (double)NB_CELL_POS;
	mm->cell_offset.x = p->cell_pos.x * buf;
	mm->cell_offset.y = p->cell_pos.y * buf;
	mm->nb_cells.x = mm->size.x / mm->cell_size + 1;
	mm->nb_cells.y = mm->size.y / mm->cell_size + 1;
	mm->first_cell.x = p->pos.x - mm->nb_cells.x / 2;
	mm->first_cell.y = p->pos.y - mm->nb_cells.y / 2;
	// to test
	// printf("\nplayer position: %d, y: %d\n",
	// 	p->pos.x, p->pos.y);
	// printf("player cell position: %d, y: %d\n",
	// 	p->cell_pos.x, p->cell_pos.y);
	// printf("Mini map cell offset: %d, y: %d\n",
	// 	mm->cell_offset.x, mm->cell_offset.y);
	// printf("Mini map number of cells: %d, y: %d\n",
	// 	mm->nb_cells.x, mm->nb_cells.y);
	// printf("Mini map first cell: %d, y: %d\n\n",
	// 	mm->first_cell.x, mm->first_cell.y);
}

void	*ft_mini_map(t_game *game)
{
	t_mini_map	*mm;
	
	mm = &(game->mini_map);
	ft_mm_init(game->player, mm);
	ft_mm_print(game, game->map, mm, &(game->mm_img));
	return (0);
}
