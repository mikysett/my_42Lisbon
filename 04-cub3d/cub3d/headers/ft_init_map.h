/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:43:09 by msessa            #+#    #+#             */
/*   Updated: 2021/03/26 17:45:59 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_MAP_H
# define FT_INIT_MAP_H
# define MIN_MAP_PARAMS 9

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

typedef enum	e_map_el
{
	empty,
	wall,
	item,
	player
}				t_map_el;

typedef struct	s_size
{
	int x;
	int y;
}				t_size;

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
	t_size	position;
	int		direction;
}				t_player;


typedef struct	s_map
{
	t_size		map_size;
	t_player	player;
	t_list		**map_params;
	t_map_el	**map_grid;
}				t_map;

t_map	*ft_init_map(char *map_path);
int		get_next_line(int fd, char **line);

t_map	*ft_free_map(t_map *map);
void	ft_free_split(char **str);
t_map	*ft_alloc_map(void);

int		ft_init_map_param(int fd, t_map *map, char **line, bool *params_set);

int		ft_init_map_size(int fd, t_map *map, char **line);

bool	ft_is_map_grid(char *line, bool *p_set);
int		ft_count_param_args(char **params);
bool	ft_param_double(t_map_p_types p_type, bool *p_set);
bool	ft_is_map_el(char c);

int		ft_set_map_grid(t_map *map, char *map_path);

#endif