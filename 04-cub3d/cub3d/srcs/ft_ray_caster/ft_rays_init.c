/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:19:20 by msessa            #+#    #+#             */
/*   Updated: 2021/04/03 00:15:17 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"


void		ft_save_cell_x(t_map *map, t_size *pos, t_size *cell_pos, t_size move)
{
	int	new_cell_pos_x;

	new_cell_pos_x = cell_pos->x + move.x;
	if (new_cell_pos_x < 0)
	{
		if (map->map_grid[pos->x - 1][pos->y].type != wall)
		{
			pos->x -= 1;
			cell_pos->x = NB_CELL_POS + new_cell_pos_x;
		}
		else
			cell_pos->x = 0;
	}
	else if (new_cell_pos_x >= NB_CELL_POS)
	{
		if (map->map_grid[pos->x + 1][pos->y].type != wall)
		{
			pos->x += 1;
			cell_pos->x = new_cell_pos_x - NB_CELL_POS;
		}
		else
			cell_pos->x = NB_CELL_POS - 1;
	}
	else
		cell_pos->x = new_cell_pos_x;
}

void		ft_save_cell_y(t_map *map, t_size *pos, t_size *cell_pos, t_size move)
{
	int	new_cell_pos_y;

	new_cell_pos_y = cell_pos->y + move.y;
	if (new_cell_pos_y < 0)
	{
		if (map->map_grid[pos->x][pos->y - 1].type != wall)
		{
			pos->y -= 1;
			cell_pos->y = NB_CELL_POS + new_cell_pos_y;
		}
		else
			cell_pos->y = 0;
	}
	else if (new_cell_pos_y >= NB_CELL_POS)
	{
		if (map->map_grid[pos->x][pos->y + 1].type != wall)
		{
			pos->y += 1;
			cell_pos->y = new_cell_pos_y - NB_CELL_POS;
		}
		else
			cell_pos->y = NB_CELL_POS - 1;
	}
	else
		cell_pos->y = new_cell_pos_y;
}

void	ft_set_first_ray(t_game *game, t_ray *ray)
{
	double		ray_dir;
	t_size		ray_move;
	t_player	*p;

	p = game->player;
	ray->pos = p->pos;
	ray->cell_pos = p->cell_pos;
	ray_dir = p->dir + DEGREES_33;
	ray_move.x = cos(ray_dir) * (CAMERA_DIST);
	ray_move.y = -(int)(sin(ray_dir) * (CAMERA_DIST));
	ft_save_cell_x(game->map, &(ray->pos), &(ray->cell_pos), ray_move);
	ft_save_cell_y(game->map, &(ray->pos), &(ray->cell_pos), ray_move);
}

void	ft_set_last_ray(t_game *game, t_ray *ray)
{
	double		ray_dir;
	t_size		ray_move;
	t_player	*p;

	p = game->player;
	ray->pos = p->pos;
	ray->cell_pos = p->cell_pos;
	ray_dir = p->dir - DEGREES_33;
	ray_move.x = cos(ray_dir) * (CAMERA_DIST);
	ray_move.y = -(int)sin(ray_dir) * (CAMERA_DIST);
	ft_save_cell_x(game->map, &(ray->pos), &(ray->cell_pos), ray_move);
	ft_save_cell_y(game->map, &(ray->pos), &(ray->cell_pos), ray_move);
}

void print_first_last_ray(t_player *p, t_ray *f_ray, t_ray *l_ray)
{
	printf("PLAYER\n");
	printf("player pos : x: %d, y: %d\n", p->pos.x, p->pos.y);
	printf("player cell: x: %d, y: %d\n\n", p->cell_pos.x, p->cell_pos.y);
	printf("RAYS\n");
	printf("RAYS  | FIRST             ||  LAST\n");
	printf("  pos : x: %4d,   y: %4d  ||  x: %4d,   y: %4d\n", f_ray->pos.x, f_ray->pos.y, l_ray->pos.x, l_ray->pos.y);
	printf("  cell: x: %4d,   y: %4d  ||  x: %4d,   y: %4d\n\n", f_ray->cell_pos.x, f_ray->cell_pos.y, l_ray->cell_pos.x, l_ray->cell_pos.y);
}

void	ft_rays_init(t_game *game, t_ray *rays, t_size res)
{
	int		i;

	ft_set_first_ray(game, rays);
	ft_set_last_ray(game, rays + res.x - 1);
	print_first_last_ray(game->player, rays, rays + res.x - 1);
	i = 0;
	while (i < res.x)
	{
		i++;
	}
}