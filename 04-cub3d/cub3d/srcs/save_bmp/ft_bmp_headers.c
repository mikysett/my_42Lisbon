/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp_headers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:34:45 by msessa            #+#    #+#             */
/*   Updated: 2021/04/25 19:35:11 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_write_bmp_header(int fd, t_bmp_info *bmp)
{
	write(fd, &bmp->identifier, 2);
	write(fd, &bmp->file_size, 4);
	write(fd, &bmp->unused_bytes, 4);
	write(fd, &bmp->pix_array_offset, 4);
}

void	ft_write_dib_header(int fd, t_bmp_info *bmp)
{
	int	i;

	i = 0;
	write(fd, &bmp->dib_header_size, 4);
	write(fd, &bmp->img_width, 4);
	write(fd, &bmp->img_height, 4);
	write(fd, &bmp->nb_color_planes, 2);
	write(fd, &bmp->bits_per_pixel, 2);
	write(fd, &bmp->compression, 4);
	write(fd, &bmp->bmp_array_size, 4);
	write(fd, &bmp->x_resolution, 4);
	write(fd, &bmp->y_resolution, 4);
	write(fd, &bmp->clrs_palette, 4);
	write(fd, &bmp->important_clrs, 4);
	write(fd, &bmp->red_mask, 4);
	write(fd, &bmp->green_mask, 4);
	write(fd, &bmp->blue_mask, 4);
	write(fd, &bmp->alpha_mask, 4);
	write(fd, &bmp->color_space, 4);
	while (i++ < 12)
		write(fd, &bmp->unused_bytes, 4);
}
