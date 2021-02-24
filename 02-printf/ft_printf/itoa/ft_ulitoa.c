/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:29:33 by msessa            #+#    #+#             */
/*   Updated: 2021/02/24 12:13:35 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa.h"

static int	ft_set_digits(unsigned long int n)
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

static void	ft_save_pos_nb(char *res, unsigned long int n, int digits)
{
	res[digits] = '0' + (n % 10);
	while ((n /= 10) != 0)
		*(res + --digits) = '0' + (n % 10);
}

static void	ft_save_neg_nb(char *res, unsigned long int n, int digits)
{
	res[digits] = '0' - (n % 10);
	while ((n /= 10) != 0)
		*(res + --digits) = '0' - (n % 10);
}

char		*ft_ulitoa(unsigned long int n)
{
	char	*res;
	int		digits;
	int		neg;

	digits = ft_set_digits(n / 10);
	neg = n < 0 ? 1 : 0;
	res = malloc(sizeof(char) * (digits + neg + 1));
	if (!res)
		return (0);
	if (!neg)
		ft_save_pos_nb(res, n, digits - 1);
	else
	{
		*res = '-';
		ft_save_neg_nb(res, n, digits);
	}
	res[digits + neg] = '\0';
	return (res);
}
