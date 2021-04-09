/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:26:03 by msessa            #+#    #+#             */
/*   Updated: 2021/04/09 12:03:20 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_cub3d.h"

int	ft_error(t_errors err)
{
	printf("Error\n");
	if (err == err_params)
		printf("Too few params passed\n");
	else if (err == err_map_extension)
		printf("Map file must be a .cub file\n");
	else if (err == err_map_path)
		printf("Map file not found\n");
	else if (err == err_map_malloc)
		printf("Failed to allocate memory for the map\n");
	else if (err == err_map_gnl)
		printf("Failed to get next line in map file\n");
	else if (err == err_map_split)
		printf("Failed to load map parameters\n");
	else if (err == err_map_param)
		printf("Invalid parameter in map file\n");
	else if (err == err_map_grid)
		printf("Error in the map grid\n");
	else if (err == err_map_param_miss)
		printf("Mandatory parameters are missing\n");
	else
		printf("Unknown error\n");
	return (0);
}

int	ft_mlx_error(t_mlx_errors err)
{
	printf("Error\n");
	if (err == err_mlx)
		printf("Failed to open the window\n");
	if (err == err_tex)
		printf("Failed to process textures\n");
	// else if (err == err_map_extension)
	// 	printf("Map file must be a .cub file\n");
	// else if (err == err_map_path)
	// 	printf("Map file not found\n");
	// else if (err == err_map_malloc)
	// 	printf("Failed to allocate memory for the map\n");
	// else if (err == err_map_gnl)
	// 	printf("Failed to get next line in map file\n");
	// else if (err == err_map_split)
	// 	printf("Failed to load map parameters\n");
	// else if (err == err_map_param)
	// 	printf("Invalid parameter in map file\n");
	// else if (err == err_map_grid)
	// 	printf("Error in the map grid\n");
	// else if (err == err_map_param_miss)
	// 	printf("Mandatory parameters are missing\n");
	else
		printf("Unknown MLX error\n");
	return (0);
}

static int	ft_isextension(char *f, char *ext)
{
	int	f_len;
	int	ext_len;

	f_len = strlen(f);
	ext_len = strlen(ext);
	while (--f_len > 0 && --ext_len > 0)
		if (f[f_len] != ext[ext_len])
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	// int		i;

	// i = 0;
	// while (i < 100000)
	// {
		if (argc < 2)
			return (ft_error(err_params));
		if (!ft_isextension(argv[1], ".cub"))
			return (ft_error(err_map_extension));
		map = ft_init_map(argv[1]);
		if (!map)
			return (0);
		ft_run_game(map);
		ft_free_map(map);
	// 	i++;
	// }
	return (0);
}
