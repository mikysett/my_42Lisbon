/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:06:56 by msessa            #+#    #+#             */
/*   Updated: 2021/03/26 16:25:50 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_cub3d.h"

void	ft_print_split(char **str)
{
	int	i;

	i = 0;
	printf("--> PRINT SPLIT\n");
	if (!str)
	{
		printf("NULL pointer\n");
		return ;
	}
	while (str[i])
	{
		printf("%3d: %s\n", i, str[i]);
		i++;
	}
}

void	ft_print_params_set(bool *param_set)
{
	int	i;

	i = 0;
	printf("--> Print params_set\n");
	while (i < MIN_MAP_PARAMS)
	{
		printf("%d: %d | ", i, param_set[i]);
		i++;
	}
	printf("\n");
}
