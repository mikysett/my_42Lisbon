/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:45:40 by msessa            #+#    #+#             */
/*   Updated: 2021/04/22 19:14:07 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEXTURES_H
# define FT_TEXTURES_H

void	ft_draw_sprites(t_game *game);
void	ft_clear_sprites(void *void_sprite);

bool	ft_init_sprites(t_game *game);
void	ft_set_sprites(t_game *game);
void	ft_item_picked(t_game *game, int x, int y);

void	ft_draw_line(t_game *game, t_vert_line *line);
void	ft_sort_sprites(t_game *game);

bool	ft_init_tex(t_game *game);

#endif