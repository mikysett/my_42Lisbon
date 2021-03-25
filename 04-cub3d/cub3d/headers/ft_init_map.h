/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:43:09 by msessa            #+#    #+#             */
/*   Updated: 2021/03/25 16:10:46 by msessa           ###   ########.fr       */
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
	t_size	resolution;
	t_color	color;
	char	*texture;
}				t_map_p_val;


typedef struct	s_map_par
{
	t_map_p_types		type;
	t_map_p_val			value;
	struct s_map_par	*next;
}				t_map_par;


typedef struct	s_map
{
	t_map_par	**map_params;
	t_size		map_size;
	t_map_el	**map_grid;
}				t_map;

t_map	*ft_init_map(char *map_path);
void	ft_free_map(t_map *map);
int		get_next_line(int fd, char **line);

#endif