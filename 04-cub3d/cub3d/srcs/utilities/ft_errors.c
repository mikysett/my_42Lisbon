/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:53:55 by msessa            #+#    #+#             */
/*   Updated: 2021/04/23 11:54:40 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

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
	if (err == err_sprite)
		printf("Failed to allocate sprites\n");
	if (err == err_save_bmp)
		printf("Failed to create the screenshot\n");
	else
		printf("Unknown MLX error\n");
	return (0);
}
