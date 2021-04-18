/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:34:11 by msessa            #+#    #+#             */
/*   Updated: 2021/04/18 17:47:36 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
// # include "../minilibx-linux/mlx.h"
# include "../minilibx/mlx.h"
# include <mlx.h>
# include "../libft/libft.h"
# include "ft_constants.h"
# include "ft_types.h"
# include "ft_errors.h"
# include "ft_mem_utilities.h"
# include "ft_init_map.h"
# include "ft_init_game.h"
# include "ft_textures.h"
# include "ft_bonus.h"
# include "ft_ray_caster.h"
# include "ft_mini_map.h"
# include "ft_set_events.h"
# include "ft_run_game.h"
# include "ft_tests.h"

int	ft_error(t_errors err);
int	ft_mlx_error(t_mlx_errors err);
#endif