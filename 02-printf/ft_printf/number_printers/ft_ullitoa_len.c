/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:31:57 by msessa            #+#    #+#             */
/*   Updated: 2021/03/01 17:26:01 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number_printers.h"

static int	ft_set_digits(unsigned long long int n)
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

static void	ft_save_nb(char *res, unsigned long long int n)
{
	*(res) = '0' + (n % 10);
	while ((n /= 10) != 0)
		*(--res) = '0' + (n % 10);
}

static void	ft_init_nb(char *res, int len)
{
	while (len--)
		*(res++) = '0';
}

static int	ft_set_mem_size(int digits, int len)
{
	int		mem_size;

	if (digits >= len)
		mem_size = digits;
	else
		mem_size = len;
	return (mem_size);
}

char		*ft_ullitoa_len(unsigned long long int n, int len)
{
	char	*res;
	int		digits;
	int		mem_size;

	if (n == 0)
	{
		if (len == 0)
			digits = 0;
		else
			digits = 1;
	}
	else
		digits = ft_set_digits(n / 10);
	mem_size = ft_set_mem_size(digits, len);
	res = malloc(sizeof(char) * (mem_size + 1));
	if (!res)
		return (0);
	res[mem_size] = '\0';
	if (digits < len)
		ft_init_nb(res, len - digits);
	if (mem_size > 0)
		ft_save_nb((res + mem_size - 1), n);
	return (res);
}
