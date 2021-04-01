/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:57:35 by msessa            #+#    #+#             */
/*   Updated: 2021/04/01 19:34:21 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_MAP_H
# define FT_MINI_MAP_H
# define MINI_MAP_WIDTH		280
# define MINI_MAP_HEIGHT	280
# define MINI_MAP_CELL_SIZE	14
# define MINI_MAP_PADDING	20
# define PLAYER_SIZE		4
# define CLR_BG			0x44000044
# define CLR_FLOOR		0x44000022
# define CLR_WALL		0x44000088
# define CLR_PLAYER		0x44880000
# define CLR_DIR		0x44008800

void	*ft_mini_map(t_game *game);
void	ft_mm_print(t_game *game, t_map *map, t_mini_map *mm, t_img_data *img);
int		ft_set_cell_y(t_mini_map *mm, int y);
int		ft_set_cell_x(t_mini_map *mm, int x);

#endif
