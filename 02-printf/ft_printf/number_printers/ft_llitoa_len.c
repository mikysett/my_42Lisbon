/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:31:57 by msessa            #+#    #+#             */
/*   Updated: 2021/03/01 17:20:31 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number_printers.h"

static int	ft_set_digits(long long int n)
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

static void	ft_save_nb(char *res, long long int n)
{
	if (n >= 0)
	{
		*(res) = '0' + (n % 10);
		while ((n /= 10) != 0)
			*(--res) = '0' + (n % 10);
	}
	else
	{
		*(res) = '0' - (n % 10);
		while ((n /= 10) != 0)
			*(--res) = '0' - (n % 10);
	}
}

static void	ft_init_nb(char *res, int neg, int len, t_arg *arg)
{
	if (neg || arg->flags[plus] == true || arg->flags[space] == true)
	{
		if (!neg)
		{
			if (arg->flags[plus] == true)
				*res = '+';
			else
				*res = ' ';
		}
		else
			*res = '-';
		res++;
	}
	if (len > 0)
		while (len--)
			*(res++) = '0';
}

static int	ft_set_mem_size(int digits, int neg, int len, t_arg *arg)
{
	int		mem_size;

	if (digits >= len)
		mem_size = digits;
	else
		mem_size = len;
	if (neg)
		mem_size++;
	else if (arg->flags[plus] == true || arg->flags[space] == true)
		mem_size++;
	return (mem_size);
}

char		*ft_llitoa_len(long long int n, int len, t_arg *arg)
{
	char	*res;
	int		digits;
	int		neg;
	int		mem_size;

	neg = n < 0 ? 1 : 0;
	if (n == 0 && len == 0)
		digits = 0;
	else
		digits = ft_set_digits(n / 10);
	mem_size = ft_set_mem_size(digits, neg, len, arg);
	res = malloc(sizeof(char) * (mem_size + 1));
	if (!res)
		return (0);
	res[mem_size] = '\0';
	ft_init_nb(res, neg, len - digits, arg);
	if (digits > 0)
		ft_save_nb((res + mem_size - 1), n);
	return (res);
}
