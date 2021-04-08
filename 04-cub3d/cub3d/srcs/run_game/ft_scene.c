/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:49:26 by msessa            #+#    #+#             */
/*   Updated: 2021/04/08 16:00:57 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

int	ft_get_white_color(int brightness)
{
	int	color;

	color = 0xFF000000;
	color += brightness;
	color += brightness << 8;
	color += brightness << 16;
	// printf("color: %d\n", color);
	return (color);
}

void	ft_scene(t_game *game)
{
	t_size	square_size;
	int		square_color;
	int		half_height;
	int		i;
	t_size	pos;

	square_size.x = 1;
	half_height = game->res.y / 2;
	i = 0;
	ft_draw_rect(&game->scene, (t_size){x : 0, y : 0}, game->res, 0);
	while (i < game->res.x)
	{
		square_size.y = game->res.y / game->rays[i].dist;
		if (square_size.y > game->res.y)
			square_size.y = game->res.y;
		square_color = 255 / game->rays[i].dist;
		if (square_color > 255)
			square_color = 255;
		else if (square_color < 15)
			square_color = 15;

		// To test
		// printf("i%4d- r dist: %f, s.y: %3d | ", i, game->rays[i].dist, square_size.y);
		// if ((i + 1) % 5 == 0)
		// 	printf("\n");
		// printf("square_size: %d\n", square_size.y);



		// square_size.y = game->res.y - (game->rays[i].dist * 80);
		// if (square_size.y > game->res.y)
		// 	square_size.y = game->res.y;
		// square_color = 255 - (game->rays[i].dist * 20.0);
		// if (square_color < 20)
		// 	square_color = 20;


		pos.x = i;
		pos.y = half_height - square_size.y / 2;
		// ft_draw_rect(&game->scene, pos, square_size, ft_get_white_color(square_color));
		ft_draw_rect(&game->scene, pos, square_size, game->rays[i].color);
		i++;
	}
}