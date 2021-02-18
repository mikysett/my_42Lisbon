/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:05:21 by msessa            #+#    #+#             */
/*   Updated: 2021/02/18 17:14:44 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_set_arg_flags(t_arg *arg, char *str)
{
	t_flags	*flags;
	int		i;
	size_t	nb_flags;

	nb_flags = 0;
	while (ft_is_flag(str[nb_flags]))
		nb_flags++;
	if (!(flags = malloc(sizeof(t_flags) * (nb_flags + 1))))
		return (0);
	flags[nb_flags] = none;
	i = 0;
	while (i < nb_flags)
	{
		flags[i] = ft_convert_flag(str[i]);
		i++;
	}
	arg->flags = flags;
	return (str + nb_flags);
}

char	*ft_set_arg_width(t_arg *arg, char *str)
{
	if (*str == '*')
	{
		arg->width_as_arg = true;
		return (str + 1);
	}
	arg->width_as_arg = false;
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
	arg->precision_as_arg = false;
	str++;
	if (*str == '*')
	{
		arg->precision_as_arg = true;
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
	return (str);
}

char	*ft_set_arg_conv(t_arg *arg, char *str)
{

	if (!ft_is_conversion(*str))
		return (0);
	arg->conv = *str;
	return (str + 1);
}

