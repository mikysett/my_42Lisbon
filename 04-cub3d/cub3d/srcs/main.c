/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:26:03 by msessa            #+#    #+#             */
/*   Updated: 2021/04/23 11:57:57 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_cub3d.h"

static int	ft_isextension(char *f, char *ext)
{
	int	f_len;
	int	ext_len;

	f_len = strlen(f);
	ext_len = strlen(ext);
	while (--f_len > 0 && --ext_len > 0)
		if (f[f_len] != ext[ext_len])
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc < 2)
		return (ft_error(err_params));
	if (!ft_isextension(argv[1], ".cub"))
		return (ft_error(err_map_extension));
	map = ft_init_map(argv[1]);
	if (!map)
		return (0);
	if (argc >= 3 && !strcmp(argv[2], "--save"))
		ft_run_game(map, true);
	else
		ft_run_game(map, false);
	ft_free_map(map);
	return (0);
}
