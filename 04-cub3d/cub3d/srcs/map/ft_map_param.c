/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:16:37 by msessa            #+#    #+#             */
/*   Updated: 2021/03/26 18:21:32 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static t_color	ft_get_color(char *clr_str)
{
	t_color	clr;
	char	**clr_arr;
	int		nb_clr;

	clr_arr = ft_split(clr_str, ',');
	nb_clr = ft_count_param_args(clr_arr);
	if (nb_clr != 3)
	{
		ft_free_split(clr_arr);
		return ((t_color){red: -1, green: -1, blue: -1});
	}
	clr.red = ft_atoi(clr_arr[0]);
	clr.green = ft_atoi(clr_arr[1]);
	clr.blue = ft_atoi(clr_arr[2]);
	ft_free_split(clr_arr);
	return (clr);
}

static bool	ft_set_param_value(t_map_par *new_p, char **param, int nb_args)
{
	if (new_p->type == resolution && nb_args == 3)
	{
		new_p->val.res.x = ft_atoi(param[1]);
		new_p->val.res.y = ft_atoi(param[2]);
		if (new_p->val.res.x >= 600 && new_p->val.res.y >= 400)
			return (true);
	}
	else if (new_p->type >= nord_tex && new_p->type <= sprite_tex
		&& nb_args == 2)
	{
		new_p->val.texture = ft_strdup(param[1]);
		return (true);
	}
	else if ((new_p->type == floor_col || new_p->type == ceiling_col)
		&& nb_args == 2)
	{
		new_p->val.clr = ft_get_color(param[1]);
		if (new_p->val.clr.red >= 0 && new_p->val.clr.red <= 255
			&& new_p->val.clr.green >= 0 && new_p->val.clr.green <= 255
			&& new_p->val.clr.blue >= 0 && new_p->val.clr.blue <= 255)
			return (true);
	}
	return (false);
}

static bool	ft_set_param_type(t_map_par *new_p, char *param_type)
{
	if (!ft_strncmp("R", param_type, 2))
		new_p->type = resolution;
	else if (!ft_strncmp("NO", param_type, 2))
		new_p->type = nord_tex;
	else if (!ft_strncmp("SO", param_type, 2))
		new_p->type = south_tex;
	else if (!ft_strncmp("WE", param_type, 2))
		new_p->type = west_tex;
	else if (!ft_strncmp("EA", param_type, 2))
		new_p->type = east_tex;
	else if (!ft_strncmp("S", param_type, 2))
		new_p->type = sprite_tex;
	else if (!ft_strncmp("F", param_type, 2))
		new_p->type = floor_col;
	else if (!ft_strncmp("C", param_type, 2))
		new_p->type = ceiling_col;
	else
		return (false);
	return (true);
}

static bool	ft_set_param(t_map *map, char **param, int nb_args, bool *p_set)
{
	t_map_par	*new_p;

	new_p = malloc(sizeof(t_map_par));
	if (!new_p)
		return (false);
	if (!ft_set_param_type(new_p, param[0]))
	{
		free(new_p);
		return (false);
	}
	if (ft_param_double(new_p->type, p_set)
		|| !ft_set_param_value(new_p, param, nb_args))
	{
		free(new_p);
		return (false);
	}
	ft_lstadd_front(map->map_params, ft_lstnew(new_p));
	return (true);
}

static bool	ft_save_map_param(t_map *map, char *line, bool *p_set)
{
	char	**param;
	int		nb_args;

	if (*line == '\0')
		return (true);
	param = ft_split(line, ' ');
	if (!param)
	{
		ft_error(err_map_split);
		return (false);
	}
	// to test
	ft_print_split(param);
	nb_args = ft_count_param_args(param);
	if (!ft_set_param(map, param, nb_args, p_set))
	{
		ft_error(err_map_param);
		ft_free_split(param);
		return (false);
	}
	ft_free_split(param);
	return (true);
}

int	ft_init_map_param(int fd, t_map *map, char **line, bool *params_set)
{
	int		read_out;
	bool	check_p;

	check_p = true;
	read_out = get_next_line(fd, line);
	while (read_out > 0)
	{
		if (ft_is_map_grid(*line, params_set))
			break ;
		check_p = ft_save_map_param(map, *line, params_set);
		free(*line);
		if (check_p == false)
			break ;
		read_out = get_next_line(fd, line);
		if (read_out < 0)
			ft_error(err_map_gnl);
	}
	if (read_out == 0)
		free(*line);
	if (read_out < 0 || check_p == false)
		return (-1);
	return (read_out);
}
