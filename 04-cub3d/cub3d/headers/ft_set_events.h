/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:31:53 by msessa            #+#    #+#             */
/*   Updated: 2021/04/01 17:30:10 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_EVENTS_H
# define FT_SET_EVENTS_H
# if IS_OS_MAC == 1

# else
#  define KEY_ARR_LEFT	65361
#  define KEY_ARR_RIGHT	65363
#  define KEY_ARR_UP	65362
#  define KEY_ARR_DOWN	65364
#  define KEY_ESC		65307
#  define KEY_MOV_LEFT	97
#  define KEY_MOV_RIGHT	100
#  define KEY_MOV_UP	119
#  define KEY_MOV_DOWN	115

#  define DESTROY_NOTIFY	33
#  define DESTROY_NOTIFY_M	0
#  define KEY_PRESS			2
#  define KEY_PRESS_M		1
#  define KEY_RELEASE		3
#  define KEY_RELEASE_M		2
# endif

void	ft_set_events(t_game *game);
bool	ft_player_moved(t_player *player);
t_size	ft_ply_take_move(bool *moving);
void	ft_ply_moving(t_map *map, t_player *player, t_size move);

#endif