/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:26:03 by msessa            #+#    #+#             */
/*   Updated: 2021/03/25 14:35:05 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_cub3d.h"

int	ft_error(t_errors err)
{
	printf("Error\n");
	if (err == err_params)
		printf("Too few params passed\n");
	else if (err == err_map_path)
		printf("Map file not found\n");
	else if (err == err_map_malloc)
		printf("Failed to allocate memory for the map\n");
	else if (err == err_map_gnl)
		printf("Failed to get next line in map file\n");
	else
		printf("Unknown error\n");
	
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc < 2)
		return (ft_error(err_params));
	map = ft_init_map(argv[1]);
	if (!map)
		return (0);
	
	ft_free_map(map);
	return (0);
}