/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:34:11 by msessa            #+#    #+#             */
/*   Updated: 2021/03/28 18:32:50 by msessa           ###   ########.fr       */
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
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "ft_errors.h"
# include "ft_mem_utilities.h"
# include "ft_init_map.h"
# include "ft_tests.h"
# define BUFFER_SIZE 64

int	ft_error(t_errors err);
#endif