/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:43:09 by msessa            #+#    #+#             */
/*   Updated: 2021/04/02 20:08:36 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_GAME_H
# define FT_INIT_GAME_H

typedef struct s_img_data
{
	void	*img_ref;
	char	*img_addr;
	int		bits_pix;
	int		size_line;
	int		endian;
}				t_img_data;

typedef struct s_mini_map
{
	t_size		size;
	int			cell_size;
	t_size		cell_offset;
	t_size		nb_cells;
	t_size		first_cell;
}				t_mini_map;

typedef struct s_ray
{
	// int size;
	t_size	pos;
	t_size	cell_pos;
}				t_ray;

typedef struct s_game
{
	t_map		*map;
	t_mini_map	mini_map;
	t_img_data	mm_img;
	t_size		mm_pos;
	t_size		res;
	t_player	*player;
	t_ray		*rays;
	void		*mlx;
	void		*win;
	void		*text;
}				t_game;

void	ft_free_game(t_game *game);
int		ft_exit_game(int key, void *game);
bool	ft_init_game(t_game *game, t_map *map);

#endif