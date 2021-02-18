/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:46:22 by msessa            #+#    #+#             */
/*   Updated: 2021/02/18 17:42:47 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		ft_is_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X'
		|| c == 'n' || c == 'f' || c == 'g' || c == 'e')
		return (true);
	return (false);
}

static char	*ft_set_arg_type_std(t_arg *arg, char *str)
{
	if (arg->conv == 'd' || arg->conv == 'i')
		arg->type = tp_int;
	else if (arg->conv == 'u' || arg->conv == 'x' || arg->conv == 'X')
		arg->type = tp_uint;
	else if (arg->conv == 'c')
		arg->type = tp_uchar;
	else if (arg->conv == 's')
		arg->type = tp_char_ptr;
	else
		return (0);
	return (str);	
}

static char	*ft_set_arg_type_l(t_arg *arg, char *str)
{
	if (arg->len_mod == l && (arg->conv == 'd' || arg->conv == 'i'))
		arg->type = tp_lint;
	else if (arg->len_mod == l && (arg->conv == 'u'
		|| arg->conv == 'x' || arg->conv == 'X'))
		arg->type = tp_ulint;
	else if (arg->len_mod == ll && (arg->conv == 'd' || arg->conv == 'i'))
		arg->type = tp_llint;
	else if (arg->len_mod == ll && (arg->conv == 'u'
		|| arg->conv == 'x' || arg->conv == 'X'))
		arg->type = tp_ullint;
	else if (arg->len_mod == l && arg->conv == 'c')
		arg->type = tp_wint;
	else if (arg->len_mod == l && arg->conv == 's')
		arg->type = tp_wchar_ptr;
	else
		return (0);
	return (str);	
}

static char	*ft_set_arg_type_h(t_arg *arg, char *str)
{
	if (arg->len_mod == h && (arg->conv == 'd' || arg->conv == 'i'))
		arg->type = tp_short;
	else if (arg->len_mod == h && (arg->conv == 'u'
		|| arg->conv == 'x' || arg->conv == 'X'))
		arg->type = tp_ushort;
	else if (arg->len_mod == hh && (arg->conv == 'd' || arg->conv == 'i'))
		arg->type = tp_char;
	else if (arg->len_mod == hh && (arg->conv == 'u'
		|| arg->conv == 'x' || arg->conv == 'X'))
		arg->type = tp_uchar;
	else
		return (0);
	return (str);	
}

char		*ft_set_arg_type(t_arg *arg, char *str)
{
	if (arg->len_mod == none)
		return (ft_set_arg_type_std(arg, str));
	else if (arg->len_mod == l || arg->len_mod == ll)
		return (ft_set_arg_type_l(arg, str));
	else if (arg->len_mod == h || arg->len_mod == hh)
		return (ft_set_arg_type_h(arg, str));
}
