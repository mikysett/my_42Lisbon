/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:43:09 by msessa            #+#    #+#             */
/*   Updated: 2021/04/10 22:20:12 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_MAP_H
# define FT_INIT_MAP_H

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