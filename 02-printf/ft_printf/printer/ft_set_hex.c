/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:27:20 by msessa            #+#    #+#             */
/*   Updated: 2021/02/26 13:59:19 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"

static int	ft_set_digits(unsigned long long int n)
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

static void	ft_save_nb(char *res, unsigned long long int n,
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

static void	ft_init_nb(char *res, int len, bool alt)
{
	if (alt == true)
		res += 2;
	while (len--)
		*(res++) = '0';
}

static char	*ft_alloc_len(int mem_size, bool alt, char c_base)
{
	char	*res;

	res = malloc(sizeof(char) * (mem_size + 1));
	if (!res)
		return (0);
	if (alt)
	{
		*res = '0';
		*(res + 1) = c_base == 'a' ? 'x' : 'X'; 
	}
	res[mem_size] = '\0';
	return (res);
}

static int	ft_set_mem_size(int digits, int len, bool alt)
{
	int		mem_size;
	
	if (digits >= len)
		mem_size = digits;
	else
		mem_size = len;
	if (alt)
		return (mem_size + 2);
	return (mem_size);
}

char		*ft_set_hex(unsigned long long int n, int len, char c_base, bool alt)
{
	char	*res;
	int		digits;
	int		mem_size;

	if (n == 0)
	{
		alt = false;
		if (len == 0)
			digits = 0;
		else
			digits = 1;
	}
	else
		digits = ft_set_digits(n / 16);
	mem_size = ft_set_mem_size(digits, len, alt);
	res = ft_alloc_len(mem_size, alt, c_base);
	if (!res)
		return (0);
	if (digits < len)
		ft_init_nb(res, len - digits, alt);
	if (mem_size > 0)
		ft_save_nb(res, n, mem_size, c_base);
	return (res);
}
