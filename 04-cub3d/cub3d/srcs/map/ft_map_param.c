/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:16:37 by msessa            #+#    #+#             */
/*   Updated: 2021/04/21 20:45:54 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

static bool	ft_set_param_value(t_map_par *new_p, char **param, int nb_args)
{
	if (new_p->type == resolution && nb_args == 3)
	{
		new_p->val.res.x = ft_atoi(param[1]);
		new_p->val.res.y = ft_atoi(param[2]);
		if (new_p->val.res.x >= MIN_RES_X && new_p->val.res.y >= MIN_RES_Y)
			return (true);
	}
	else if (((new_p->type >= nord_tex && new_p->type <= trap_tex)
			|| new_p->type >= skybox_tex) && nb_args == 2)
	{
		new_p->val.texture = ft_strdup(param[1]);
		return (true);
	}
	else if ((new_p->type == floor_col || new_p->type == ceiling_col)
		&& nb_args == 2)
	{
		new_p->val.clr = ft_get_color(param[1]);
		if (new_p->val.clr != -1)
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
		new_p->type = item_tex;
	else if (!ft_strncmp("H", param_type, 2))
		new_p->type = heal_tex;
	else if (!ft_strncmp("T", param_type, 2))
		new_p->type = trap_tex;
	else if (!ft_strncmp("F", param_type, 2))
		new_p->type = floor_col;
	else if (!ft_strncmp("C", param_type, 2))
		new_p->type = ceiling_col;
	else if (!ft_strncmp("SKY", param_type, 3))
		new_p->type = skybox_tex;
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

bool	ft_init_map_param(t_list *map_line, t_map *map, bool *params_set)
{
	while (map_line)
	{
		if (ft_is_map_grid(map_line->content, params_set))
			return (true);
		if (!ft_save_map_param(map, map_line->content, params_set))
			return (false);
		map_line = map_line->next;
	}
	return (true);
}
