/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:13:56 by msessa            #+#    #+#             */
/*   Updated: 2021/04/09 12:03:52 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

typedef enum e_errors
{
	err_params,
	err_map_extension,
	err_map_path,
	err_map_malloc,
	err_map_gnl,
	err_map_split,
	err_map_param,
	err_map_grid,
	err_map_param_miss
}				t_errors;

typedef enum e_mlx_errors
{
	err_mlx,
	err_tex
}				t_mlx_errors;
#endif