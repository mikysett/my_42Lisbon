/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:34:11 by msessa            #+#    #+#             */
/*   Updated: 2021/04/23 11:57:49 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILITIES_H
# define FT_UTILITIES_H

int		ft_error(t_errors err);
int		ft_mlx_error(t_mlx_errors err);

void	ft_free_matrix(void **matrix, int size);
void	ft_free_split(char **str);

#endif