/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:16:43 by msessa            #+#    #+#             */
/*   Updated: 2021/04/11 20:08:41 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

int	ft_get_color(char *clr_str)
{
	t_color	rgb_clr;
	char	**clr_arr;
	int		nb_clr;

	clr_arr = ft_split(clr_str, ',');
	nb_clr = ft_count_param_args(clr_arr);
	if (nb_clr != 3)
	{
		ft_free_split(clr_arr);
		return (-1);
	}
	rgb_clr.red = ft_atoi(clr_arr[0]);
	rgb_clr.green = ft_atoi(clr_arr[1]);
	rgb_clr.blue = ft_atoi(clr_arr[2]);
	ft_free_split(clr_arr);
	if (rgb_clr.red < 0 || rgb_clr.red > 255
		|| rgb_clr.green < 0 || rgb_clr.green > 255
		|| rgb_clr.blue < 0 || rgb_clr.blue > 255)
		return (-1);
	return ((rgb_clr.red << 16) + (rgb_clr.green << 8) + rgb_clr.blue);
}

bool	ft_is_map_grid(char *line, bool *p_set)
{
	while (*line == ' ')
		line++;
	if (*line == '1')
	{
		if (p_set)
			ft_param_double(map_grid, p_set);
		return (true);
	}
	return (false);
}

int	ft_count_param_args(char **params)
{
	int	i;

	i = 0;
	while (params[i] != 0)
		i++;
	return (i);
}

bool	ft_param_double(t_map_p_types p_type, bool *p_set)
{
	if (p_type >= MIN_MAP_PARAMS)
		return (false);
	if (p_set[p_type] == true)
		return (true);
	p_set[p_type] = true;
	return (false);
}

char	*ft_next_map_el(char *line)
{
	if (*line == ' ' || *line == '0' || *line == '1' || *line == '2'
		|| *line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
		return (line + 1);
	if (*line == '[')
	{
		line++;
		while (*line)
		{
			if (*line == ']')
				return (line + 1);
			line++;
		}
	}
	return (0);
}
