/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:43:09 by msessa            #+#    #+#             */
/*   Updated: 2021/04/09 20:05:26 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_GAME_H
# define FT_INIT_GAME_H

typedef enum e_game_settings
{
	show_minimap,
	show_fps
}			t_game_settings;

typedef struct s_img_data
{
	void	*img_ref;
	char	*img_addr;
	int		bits_pix;
	int		size_line;
	int		endian;
	int		width;
	int		height;
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
	t_size_f	pos;
	double		dist;
	double		dir;
	t_size_f	intersec;
	char		slope;
	bool		neg_step_x;
	bool		neg_step_y;
	double		step;
	double		diff_x;
	double		diff_y;
	double		x_incr;
	double		y_incr;
	double		tex_pos;
	int			color;
	t_tex_type	tex;
}				t_ray;

typedef struct s_rays_info
{
	double	fov;
	double	half_fov;
	double	step;

}				t_rays_info;

typedef struct s_game
{
	t_map		*map;
	t_mini_map	mini_map;
	t_img_data	mm_img;
	t_size		mm_pos;
	t_size		res;
	t_player	*player;
	t_ray		*rays;
	t_rays_info	rays_info;
	void		*mlx;
	void		*win;
	t_img_data	scene;
	int			tex_size;
	t_img_data	tex[NB_TEX];
	bool		settings[NB_SETTINGS];
	struct timeval	old_time;
	struct timeval	new_time;
}				t_game;

void	ft_free_game(t_game *game);
int		ft_exit_game(int key, void *game);
bool	ft_init_game(t_game *game, t_map *map);

#endif