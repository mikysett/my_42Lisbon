/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:15:06 by msessa            #+#    #+#             */
/*   Updated: 2021/05/06 17:30:00 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	long	i;
	long	curr_nb;
	long	next_nb;
	long	buf;

	curr_nb = 0;
	next_nb = 1;
	i = 900000;
	while (i != 0)
	{
		printf("%20ld\n", curr_nb);
		buf = curr_nb;
		curr_nb = next_nb;
		next_nb = buf + next_nb;
		i--;
	}
}