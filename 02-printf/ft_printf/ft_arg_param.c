/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:05:21 by msessa            #+#    #+#             */
/*   Updated: 2021/02/24 20:29:53 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_set_arg_flags(t_arg *arg, char *str)
{
	int		i;
	t_flags	flag_sel;

	i = 0;
	while (i < NB_FLAGS)
		arg->flags[i++] = false;
	while ((flag_sel = ft_convert_flag(*str)) != flags_none)
	{
		arg->flags[flag_sel] = true;
		str++;
	}
	return (str);
}

char	*ft_set_arg_width(t_arg *arg, char *str)
{
	if (*str == '*')
	{
		arg->w_as_arg = true;
		return (str + 1);
	}
	arg->w_as_arg = false;
	arg->width = 1;
	if (ft_isdigit(*str))
	{
		arg->width = ft_atoi(str);
		str++;
		while (ft_isdigit(*str))
			str++;
	}
	return (str);
}

char	*ft_set_arg_precision(t_arg *arg, char *str)
{
	arg->precision_set = false;
	if (*str != '.')
		return (str);
	arg->precision_set = true;
	arg->precision = 6;
	arg->p_as_arg = false;
	str++;
	if (*str == '*')
	{
		arg->p_as_arg = true;
		return (str + 1);
	}
	if (ft_isdigit(*str))
	{
		arg->precision = ft_atoi(str);
		str++;
		while (ft_isdigit(*str))
			str++;
	}
	else
		arg->precision = 0;
	return (str);
}

char	*ft_set_arg_lenmod(t_arg *arg, char *str)
{
	if (*str == 'l' && *(str + 1) == 'l')
	{
		arg->len_mod = ll;
		return (str + 2);
	}
	if (*str == 'l')
	{
		arg->len_mod = l;
		return (str + 1);
	}
	if (*str == 'h' && *(str + 1) == 'h')
	{
		arg->len_mod = hh;
		return (str + 2);
	}
	if (*str == 'h')
	{
		arg->len_mod = h;
		return (str + 1);
	}
	arg->len_mod = lm_none;
	return (str);
}

char	*ft_set_arg_conv(t_arg *arg, char *str)
{
	if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
		|| *str == 'i' || *str == 'u' || *str == 'x' || *str == 'X')
	{
		arg->conv = *str;
		return (str + 1);
	}
	return (0);
}

