/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_bmp.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:13:06 by msessa            #+#    #+#             */
/*   Updated: 2021/04/25 19:36:16 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SAVE_BMP_H
# define FT_SAVE_BMP_H

void	ft_save_bmp(t_game *game);

void	ft_write_bmp_header(int fd, t_bmp_info *bmp);
void	ft_write_dib_header(int fd, t_bmp_info *bmp);

#endif