/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:57:35 by msessa            #+#    #+#             */
/*   Updated: 2021/04/02 13:49:37 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_MAP_H
# define FT_MINI_MAP_H

void	*ft_mini_map(t_game *game);
void	ft_mm_print(t_game *game, t_map *map, t_mini_map *mm, t_img_data *img);
int		ft_set_cell_y(t_mini_map *mm, int y);
int		ft_set_cell_x(t_mini_map *mm, int x);

#endif
