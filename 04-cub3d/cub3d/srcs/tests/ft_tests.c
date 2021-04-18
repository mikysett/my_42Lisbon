/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:06:56 by msessa            #+#    #+#             */
/*   Updated: 2021/04/17 20:23:46 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

double	ft_rad_to_deg(double rad)
{
	return (rad * (180.0 / PI));
}

double	ft_deg_to_rad(double deg)
{
	return (deg * (PI / 180.0));
}

void	ft_print_rays(t_ray *rays, const int res_x)
{
	int	i;

	printf("Print rays infos:\n");
	i = 0;
	while (i < res_x)
	{
		printf("r%4d- x: %.5f, y: %.5f |  ", i, rays[i].pos.x, rays[i].pos.y);
		i++;
		if (i % 5 == 0)
			printf("\n");
	}
}

void	ft_print_split(char **str)
{
	int	i;

	i = 0;
	printf("--> PRINT SPLIT\n");
	if (!str)
	{
		printf("NULL pointer\n");
		return ;
	}
	while (str[i])
	{
		printf("%3d: %s\n", i, str[i]);
		i++;
	}
}

void	ft_print_params_set(bool *param_set)
{
	int	i;

	i = 0;
	printf("--> Print params_set\n");
	while (i < NB_MAP_PARAMS)
	{
		printf("%d: %d | ", i, param_set[i]);
		i++;
	}
	printf("\n");
}

void	ft_print_map_grid(t_map *map)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	printf("--> Printing the map in memory\n");
	while (y < map->map_size.y)
	{
		x = 0;
		while (x < map->map_size.x)
		{
			if (map->map_grid[x][y].type == empty)
				c = '_';
			else if (map->map_grid[x][y].type == e_floor)
				c = '0';
			else if (map->map_grid[x][y].type == wall)
				c = '1';
			else if (map->map_grid[x][y].type == item)
				c = '2';
			else // if (map->map_grid[x][y].type == player)
				c = 'P';
			write(1, &c, 1);
			x++;
		}
		c = '\n';
		write(1, &c, 1);
		y++;
	}
}

void	ft_print_sprites_info(t_sprite *sprites, int nb_sprites)
{
	int	i;

	i = 0;
	printf("--> Printing sprites info\n");
	while (i < nb_sprites)
	{
		printf("f_pos.x: %f\n", sprites[i].f_pos.x);
		printf("f_pos.y: %f\n", sprites[i].f_pos.y);
		// printf("dist     : %f\n", sprite->dist);
		// printf("tex_pos.x: %f\n\n", sprite->tex_pos_x);
		// printf("tex_pos.y: %d\n\n", sprite->tex_pos_y);
		printf("\n");
		i++;
	}
}
