/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_hex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:20:58 by msessa            #+#    #+#             */
/*   Updated: 2021/03/04 14:29:45 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_number_printers.h"

int		ft_set_digits_hex(unsigned long long int n)
{
	int	digits;

	digits = 1;
	while (n != 0)
	{
		n /= 16;
		digits++;
	}
	return (digits);
}

void	ft_save_nb_hex(char *res, unsigned long long int n,
	int digits, char c_base)
{
	int digit_sel;

	digits--;
	digit_sel = n % 16;
	if (digit_sel < 10)
		res[digits] = '0' + digit_sel;
	else
		res[digits] = c_base + digit_sel - 10;
	while ((n /= 16) != 0)
	{
		digit_sel = n % 16;
		if (digit_sel < 10)
			res[--digits] = '0' + digit_sel;
		else
			res[--digits] = c_base + digit_sel - 10;
	}
}
