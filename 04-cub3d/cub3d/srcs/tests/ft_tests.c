/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:06:56 by msessa            #+#    #+#             */
/*   Updated: 2021/03/27 22:34:10 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

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
	while (i < MIN_MAP_PARAMS)
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
			if (map->map_grid[y][x].type == empty)
				c = '_';
			else if (map->map_grid[y][x].type == e_floor)
				c = '0';
			else if (map->map_grid[y][x].type == wall)
				c = '1';
			else if (map->map_grid[y][x].type == item)
				c = '2';
			else // if (map->map_grid[y][x].type == player)
				c = 'P';
			write(1, &c, 1);
			x++;
		}
		c = '\n';
		write(1, &c, 1);
		y++;
	}
}
