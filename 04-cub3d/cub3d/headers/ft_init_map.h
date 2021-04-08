/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:43:09 by msessa            #+#    #+#             */
/*   Updated: 2021/04/03 16:37:23 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_MAP_H
# define FT_INIT_MAP_H

typedef enum	e_rot
{
	r_left,
	r_right
}				t_rot;

typedef enum	e_dir
{
	d_cn,
	d_t,
	d_tl,
	d_l,
	d_bl,
	d_b,
	d_br,
	d_r,
	d_tr
}				t_dir;

typedef enum	e_map_p_types
{
	resolution,
	nord_tex,
	south_tex,
	west_tex,
	east_tex,
	sprite_tex,
	floor_col,
	ceiling_col,
	map_grid
}				t_map_p_types;

typedef enum	e_map_el_type
{
	invalid,
	empty,
	e_floor,
	wall,
	item,
	player,
	door,
	enemy
}				t_map_el_type;

typedef struct	s_map_el_extra
{
	char			*text;
	char			*sprite;
	int				direction;
	int				life;
	int				height;
}				t_map_el_extra;

typedef struct	s_map_el
{
	t_map_el_type	type;
	t_map_el_extra	*extra;
}				t_map_el;

typedef struct	s_size
{
	int	x;
	int	y;
}				t_size;

typedef struct	s_size_f
{
	double	x;
	double	y;
}				t_size_f;

typedef struct	s_color
{
	int	red;
	int	green;
	int	blue;
}				t_color;

typedef union	u_map_p_val
{
	t_size	res;
	t_color	clr;
	char	*texture;
}				t_map_p_val;

typedef struct	s_map_par
{
	t_map_p_types	type;
	t_map_p_val		val;
}				t_map_par;

typedef struct	s_player
{
	t_size	pos;
	double	dir;
	t_size	cell_pos;
	t_size	last_pos;
	t_size	last_cell_pos;
	bool	moving[NB_DIRECTIONS];
	bool	rotating[2];
	int		life;
}				t_player;

typedef struct	s_map
{
	t_size		map_size;
	t_player	player;
	t_list		**map_params;
	t_map_el	**map_grid;
}				t_map;

t_map			*ft_init_map(char *map_path);
int				get_next_line(int fd, char **line);

t_map			*ft_free_map(t_map *map);
void			ft_free_map_file(t_list	**map_lines);
t_map			*ft_alloc_map(void);

t_list			**ft_save_file(char *map_path);

bool			ft_init_map_param(t_list *map_line, t_map *map,
					bool *params_set);

bool			ft_init_map_size(t_list *map_line, t_map *map);

t_color			ft_get_color(char *clr_str);
bool			ft_is_map_grid(char *line, bool *p_set);
int				ft_count_param_args(char **params);
bool			ft_param_double(t_map_p_types p_type, bool *p_set);
char			*ft_next_map_el(char *line);

bool			ft_set_map_grid(t_list *map_line, t_map *map);
bool			ft_check_map_grid(t_map_el **grid, t_size map_size);

void			ft_set_grid_line(t_map_el *grid_line, int grid_size);
t_map_el_type	ft_get_el_type(char c);
t_map_el		**ft_alloc_map_grid(t_size map_size);

#endif