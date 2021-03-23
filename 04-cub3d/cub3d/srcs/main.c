/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:26:03 by msessa            #+#    #+#             */
/*   Updated: 2021/03/23 18:29:06 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_cub3d.h"

static int	ft_error(void)
{
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (ft_error());
	ft_putstr_fd(argv[1], 1);
	return (0);
}