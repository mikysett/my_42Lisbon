/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:03:53 by msessa            #+#    #+#             */
/*   Updated: 2021/03/31 18:04:24 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_draw_rect(t_img_data *img, t_size pos, t_size size, int color)
{
	int		x;
	int		y;
	char	*img_addr;

	y = 0;
	img_addr = img->img_addr;
	img_addr += (pos.x * 4) + pos.y * img->size_line;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			*((int *)(img_addr)) = color;
			img_addr += 4;
			x++;
		}
		img_addr = img_addr - size.x * 4 + img->size_line;
		y++;
	}
}
