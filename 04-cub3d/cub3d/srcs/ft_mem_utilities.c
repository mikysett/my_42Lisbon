/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:30:37 by msessa            #+#    #+#             */
/*   Updated: 2021/03/28 18:33:09 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_cub3d.h"

void	ft_free_split(char **str)
{
	char	**o_str;

	o_str = str;
	while (*str != 0)
	{
		free(*str);
		str++;
	}
	free(o_str);
}

void	ft_free_matrix(void **matrix, int size)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
