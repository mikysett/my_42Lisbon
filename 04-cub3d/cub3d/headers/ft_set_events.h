/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:31:53 by msessa            #+#    #+#             */
/*   Updated: 2021/04/02 13:47:16 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_EVENTS_H
# define FT_SET_EVENTS_H

void	ft_set_events(t_game *game);
bool	ft_player_moved(t_player *player);
t_size	ft_ply_set_move(double player_dir, bool *moving);
void	ft_ply_set_dir(t_player *player);
void	ft_ply_set_cell_x(t_map *map, t_player *player, t_size move);
void	ft_ply_set_cell_y(t_map *map, t_player *player, t_size move);


#endif