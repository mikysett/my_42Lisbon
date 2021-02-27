/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:29:33 by msessa            #+#    #+#             */
/*   Updated: 2021/02/25 09:40:15 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa.h"

static int	ft_set_digits(unsigned int n)
{
	int	digits;

	digits = 1;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	ft_save_pos_nb(char *res, unsigned int n, int digits)
{
	res[digits] = '0' + (n % 10);
	while ((n /= 10) != 0)
		*(res + --digits) = '0' + (n % 10);
}

char		*ft_uitoa(unsigned int n)
{
	char	*res;
	int		digits;

	digits = ft_set_digits(n / 10);
	res = malloc(sizeof(char) * (digits + 1));
	if (!res)
		return (0);
	ft_save_pos_nb(res, n, digits - 1);
	res[digits] = '\0';
	return (res);
}
