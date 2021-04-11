/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 22:13:40 by msessa            #+#    #+#             */
/*   Updated: 2021/04/11 01:33:42 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Map

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

/* The _tex texture types must start this enum and be on the same order
** of enum t_tex_type */
typedef enum	e_map_p_types
{
	nord_tex,
	south_tex,
	west_tex,
	east_tex,
	sprite_tex,
	resolution,
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

// Textures

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

typedef enum	e_tex_type
{
	tex_wall_n,
	tex_wall_s,
	tex_wall_w,
	tex_wall_e
}				t_tex_type;

typedef struct	s_vert_line
{
	t_size		pos;
	int			scene_h;
	int			line_h;
	int			tex_h;
	double		offset;
	t_img_data	*tex;
	char		*tex_addr;
	double		tex_step_h_float;
	int			tex_step_h;
	int			next_step_h;
	int			step_precision;
	double		skip_texels;
}				t_vert_line;

// General game settings

typedef enum e_game_settings
{
	show_minimap,
	show_fps
}			t_game_settings;

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
	t_vert_line	line;
	void		*mlx;
	void		*win;
	t_img_data	scene;
	int			tex_size;
	t_img_data	tex[NB_TEX];
	bool		settings[NB_SETTINGS];
	struct timeval	old_time;
	struct timeval	new_time;
}				t_game;