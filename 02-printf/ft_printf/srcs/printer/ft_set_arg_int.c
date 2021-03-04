/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_arg_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:49:02 by msessa            #+#    #+#             */
/*   Updated: 2021/03/04 14:29:36 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printer.h"

static int	ft_set_nb_len(t_arg *arg)
{
	if (arg->precision_set == true && arg->precision >= 0)
	{
		arg->flags[zero] = false;
		return (arg->precision);
	}
	else if (arg->flags[minus] == false && arg->flags[zero] == true
		&& arg->width > 0)
		return (arg->width - 1);
	else
		return (1);
}

t_str_arg	ft_set_arg_d(t_str_part *sp)
{
	t_arg		*arg;
	t_str_arg	sa;
	t_len_mod	l_mod;
	int			len;

	arg = sp->arg;
	len = ft_set_nb_len(arg);
	l_mod = arg->len_mod;
	if (l_mod == lm_none)
		sa.str = ft_llitoa_len(arg->val.v_int, len, arg);
	else if (l_mod == l)
		sa.str = ft_llitoa_len(arg->val.v_lint, len, arg);
	else if (l_mod == ll)
		sa.str = ft_llitoa_len(arg->val.v_llint, len, arg);
	else if (l_mod == h)
		sa.str = ft_llitoa_len(arg->val.v_short, len, arg);
	else if (l_mod == hh)
		sa.str = ft_llitoa_len(arg->val.v_char, len, arg);
	if (!sa.str)
		return ((t_str_arg){ .str = 0, .is_freeable = false, .str_len = -1 });
	sa.is_freeable = true;
	sa.str_len = ft_strlen(sa.str);
	return (sa);
}

t_str_arg	ft_set_arg_u(t_str_part *sp)
{
	t_arg		*arg;
	t_str_arg	sa;
	t_len_mod	l_mod;
	int			len;

	arg = sp->arg;
	len = ft_set_nb_len(arg);
	l_mod = arg->len_mod;
	if (l_mod == lm_none)
		sa.str = ft_ullitoa_len(arg->val.v_uint, len);
	else if (l_mod == l)
		sa.str = ft_ullitoa_len(arg->val.v_ulint, len);
	else if (l_mod == ll)
		sa.str = ft_ullitoa_len(arg->val.v_ullint, len);
	else if (l_mod == h)
		sa.str = ft_ullitoa_len(arg->val.v_ushort, len);
	else if (l_mod == hh)
		sa.str = ft_ullitoa_len(arg->val.v_uchar, len);
	if (!sa.str)
		return ((t_str_arg){ .str = 0, .is_freeable = false, .str_len = -1 });
	sa.is_freeable = true;
	sa.str_len = ft_strlen(sa.str);
	return (sa);
}

t_str_arg	ft_set_arg_x(t_str_part *sp)
{
	t_arg		*arg;
	t_str_arg	sa;
	t_len_mod	l_mod;
	int			len;
	char		hex_c;

	arg = sp->arg;
	hex_c = arg->conv == 'X' ? 'A' : 'a';
	len = ft_set_nb_len(arg);
	l_mod = arg->len_mod;
	if (l_mod == lm_none)
		sa.str = ft_set_hex(arg->val.v_uint, len, hex_c, arg->flags[hashtag]);
	else if (l_mod == l)
		sa.str = ft_set_hex(arg->val.v_ulint, len, hex_c, arg->flags[hashtag]);
	else if (l_mod == ll)
		sa.str = ft_set_hex(arg->val.v_ullint, len, hex_c, arg->flags[hashtag]);
	else if (l_mod == h)
		sa.str = ft_set_hex(arg->val.v_ushort, len, hex_c, arg->flags[hashtag]);
	else if (l_mod == hh)
		sa.str = ft_set_hex(arg->val.v_uchar, len, hex_c, arg->flags[hashtag]);
	if (!sa.str)
		return ((t_str_arg){ .str = 0, .is_freeable = false, .str_len = -1 });
	sa.is_freeable = true;
	sa.str_len = ft_strlen(sa.str);
	return (sa);
}

t_str_arg	ft_set_arg_p(t_str_part *sp)
{
	if (sp->arg->val.v_ullint == 0)
		return (ft_set_arg_s(sp));
	sp->arg->flags[hashtag] = true;
	sp->arg->len_mod = ll;
	return (ft_set_arg_x(sp));
}
