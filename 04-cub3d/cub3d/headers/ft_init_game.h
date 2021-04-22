/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:43:09 by msessa            #+#    #+#             */
/*   Updated: 2021/04/20 13:03:22 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_GAME_H
# define FT_INIT_GAME_H

bool		ft_init_game(t_game *game, t_map *map);
void		ft_free_game(t_game *game);
int			ft_exit_game(int key, void *game);

t_size		ft_init_res(t_list **map_params);
t_player	*ft_ply_init(t_player *player);
void		ft_init_bg(t_game *game);

#endif