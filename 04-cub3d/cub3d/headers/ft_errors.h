/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:13:56 by msessa            #+#    #+#             */
/*   Updated: 2021/03/25 16:21:12 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

typedef enum	e_errors
{
	err_none,
	err_params,
	err_map_path,
	err_map_malloc,
	err_map_gnl
}				t_errors;
#endif