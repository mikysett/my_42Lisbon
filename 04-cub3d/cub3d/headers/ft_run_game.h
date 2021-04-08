/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:52:38 by msessa            #+#    #+#             */
/*   Updated: 2021/04/03 18:50:07 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUN_GAME_H
# define FT_RUN_GAME_H

void	ft_run_game(t_map *map);
int		ft_render_game(void *game);

void	ft_scene(t_game *game);

void	ft_draw_rect(t_img_data *img, t_size pos, t_size size, int color);

#endif