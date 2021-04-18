/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 22:13:40 by msessa            #+#    #+#             */
/*   Updated: 2021/04/18 18:07:06 by msessa           ###   ########.fr       */
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
	item_tex,
	heal_tex,
	trap_tex,
	resolution,
	floor_col,
	ceiling_col,
	map_grid,
	skybox_tex
}				t_map_p_types;

typedef enum	e_map_el_type
{
	invalid,
	empty,
	e_floor,
	wall,
	item,
	heal,
	trap,
	player,
	door,
	enemy
}				t_map_el_type;

typedef struct	s_map_el
{
	t_map_el_type	type;
	bool			sprite;
	bool			sprite_done;

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
	int		clr;
	char	*texture;
}				t_map_p_val;

typedef struct	s_map_par
{
	t_map_p_types	type;
	t_map_p_val		val;
}				t_map_par;

typedef struct	s_player
{
	t_size		pos;
	t_size_f	f_pos;
	double		dir;
	t_size		cell_pos;
	t_size		last_pos;
	t_size		last_cell_pos;
	bool		moving[NB_DIRECTIONS];
	bool		rotating[2];
	int			life;
}				t_player;

typedef struct	s_map
{
	t_size		map_size;
	t_player	player;
	t_list		**map_params;
	t_map_el	**map_grid;
}				t_map;

// Textures and Sprites

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
	tex_wall_e,
	tex_item,
	tex_heal,
	tex_trap
}				t_tex_type;

typedef struct s_sky_info
{
	int		height;
	double	step_h_float;
	int		step_h;
	int		step_precision;
	int		next_step_h;
}				t_sky_info;

typedef struct s_sprite
{
	t_size_f	f_pos;
	t_size_f	border_pos;
	t_img_data	*img;
	bool		in_fov;
	double		angle;

	t_size		pos;
	int			height;
	int			width;
	double		dist;
	int			ray_index;
	double		tex_pos_x;
	int			tex_pos_y;

	char		*sprite_addr;
	double		step_x;
	double		skip_texels;
	int			skipped_pix;
	int			init_next_step_h;
	int			tex_h;
	double		step_h_float;
	int			step_h;
	int			next_step_h;
	int			step_precision;
	t_map_el	*map_el;
}				t_sprite;

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

typedef struct s_lifebar
{
	t_img_data	img;
	t_size		pos;
	t_size		size;
}				t_lifebar;

typedef struct s_ray
{
	int			index;
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
	t_tex_type	tex;
}				t_ray;

typedef struct s_rays_info
{
	double	fov;
	double	half_fov;
	double	step;

}				t_rays_info;

typedef struct	s_vert_line
{
	t_ray			*ray;
	t_size			pos;
	int				scene_h;
	int				line_h;
	int				tex_h;
	unsigned int	tex_alpha;
	double			offset;
	t_img_data		*tex;
	char			*tex_addr;
	double			tex_step_h_float;
	int				tex_step_h;
	int				next_step_h;
	int				step_precision;
	double			skip_texels;
}				t_vert_line;



typedef struct s_game
{
	t_map		*map;
	t_mini_map	mini_map;
	t_size		res;
	t_player	*player;
	t_ray		*rays;
	t_rays_info	rays_info;
	t_vert_line	line;
	int			ceil_clr;
	int			floor_clr;
	void		*mlx;
	void		*win;
	t_img_data	bg;
	t_img_data	scene;
	t_img_data	obj;
	t_lifebar	lb;
	t_img_data	mm_img;
	t_size		mm_pos;
	t_img_data	sky_tex;
	t_sky_info	sky_info;
	t_img_data	tex[NB_TEX];
	int			nb_sprites;
	t_sprite	*sprites;
	bool		settings[NB_SETTINGS];
	struct timeval	old_time;
	struct timeval	new_time;
}				t_game;