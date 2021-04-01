/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mm_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:02:17 by msessa            #+#    #+#             */
/*   Updated: 2021/04/01 20:21:49 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static void	ft_print_sgl_cell(t_size cell_size, t_size printer_pos,
	t_img_data *img, t_map_el_type cell_type)
{
	if (cell_type == wall)
	{
		printer_pos.x += 1;
		printer_pos.y += 1;
		cell_size.x -= 2;
		cell_size.y -= 2;
		ft_draw_rect(img, printer_pos, cell_size, CLR_WALL);
	}
}

static void	ft_mm_print_line(t_game *game, t_size printer_pos,
	int curr_cell_y, t_size cell_size)
{
	int			x;
	t_map		*map;
	t_map_el	**map_grid;
	t_mini_map	*mm;
	int			curr_cell_x;

	map = game->map;
	map_grid = map->map_grid;
	mm = &(game->mini_map);
	x = 0;
	printer_pos.x = 0;
	while (x < mm->nb_cells.x)
	{
		curr_cell_x = mm->first_cell.x + x;
		cell_size.x = ft_set_cell_x(mm, x);
		if (x + mm->first_cell.x >= 0)
			ft_print_sgl_cell(cell_size, printer_pos, &(game->mm_img),
				map_grid[curr_cell_x][curr_cell_y].type);
		printer_pos.x += cell_size.x;
		if (curr_cell_x + 1 == map->map_size.x)
			break;
		x++;
	}
}

static void	ft_mm_print_cells(t_game *game, t_map *map, t_mini_map *mm)
{
	int		y;
	t_size	printer_pos;
	t_size	cell_size;
	t_size	curr_cell;

	y = 0;
	printer_pos = (t_size){x : 0, y : 0};
	while (y < mm->nb_cells.y)
	{
		curr_cell.y = mm->first_cell.y + y;
		cell_size.y = ft_set_cell_y(mm, y);
		if (curr_cell.y >= 0)
			ft_mm_print_line(game, printer_pos, curr_cell.y, cell_size);
		printer_pos.y += cell_size.y;
		if (curr_cell.y + 1 == map->map_size.y)
			break;
		y++;
	}
}

t_size	ft_take_dir_point(double dir)
{
	t_size	dir_point;

	dir_point.x = cos(dir) * 100.0;
	dir_point.y = sin(dir) * 100.0;
	printf("dir: %f\n", dir);
	printf("cos dir: %f, sin dir: %f\n", cos(dir), sin(dir));
	printf("dir_point.x: %d, dir_point.y: %d\n", dir_point.x, dir_point.y);
	return (dir_point);
}

static void	ft_mm_print_player(t_player *player,
	t_mini_map *mm, t_img_data *img)
{
	int	half_size_x;
	int	half_size_y;
	int	half_p_size;
	t_size	dir_point;

	half_size_x = mm->size.x / 2;
	half_size_y = mm->size.y / 2;
	half_p_size = PLAYER_SIZE / 2;
	ft_draw_rect(img,
		(t_size){x : half_size_x - half_p_size, y : half_size_y - half_p_size},
		(t_size){x : PLAYER_SIZE, y : PLAYER_SIZE}, CLR_PLAYER);
	dir_point = ft_take_dir_point(player->dir);
	ft_draw_rect(img,
		(t_size){x : half_size_x + dir_point.x, y : half_size_y - dir_point.y},
		(t_size){x : PLAYER_SIZE, y : PLAYER_SIZE}, CLR_DIR);
}

void	ft_mm_print(t_game *game, t_map *map, t_mini_map *mm, t_img_data *img)
{
	ft_draw_rect(img, (t_size){x : 0, y : 0}, mm->size, CLR_BG);
	ft_mm_print_cells(game, map, mm);
	ft_mm_print_player(game->player, mm, img);
}
