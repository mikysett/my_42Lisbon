/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:45:40 by msessa            #+#    #+#             */
/*   Updated: 2021/04/17 20:27:31 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEXTURE_H
# define FT_TEXTURE_H

void	ft_draw_sprites(t_game *game);
void	ft_clear_sprites(void *void_sprite);

bool	ft_init_sprites(t_game *game);

void	ft_draw_line(t_game *game, t_vert_line *line, int tex_size_line);

bool	ft_init_tex(t_game *game);

#endif