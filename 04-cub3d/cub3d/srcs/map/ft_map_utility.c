/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:16:43 by msessa            #+#    #+#             */
/*   Updated: 2021/03/26 16:48:16 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

bool	ft_is_map_grid(char *line, bool *p_set)
{
	while (*line == ' ')
		line++;
	if (*line == '1')
	{
		ft_param_double(map_grid, p_set);
		printf("Map grid start parsing\n");
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

// UNUSED FUNCTION FOR NOW

bool	ft_is_map_el(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == '2'
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}
