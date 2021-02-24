/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:49:02 by msessa            #+#    #+#             */
/*   Updated: 2021/02/24 12:05:40 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str_arg   ft_set_arg_d(t_str_part *sp)
{
	t_str_arg	str_arg;
	t_len_mod	l_mod;
	
	l_mod = sp->arg->len_mod;
	if ((l_mod == none && !(str_arg.str = ft_itoa(sp->arg->val.v_int)))
		|| (l_mod == l && !(str_arg.str = ft_litoa(sp->arg->val.v_lint)))
		|| (l_mod == ll && !(str_arg.str = ft_llitoa(sp->arg->val.v_llint)))
		|| (l_mod == h && !(str_arg.str = ft_sitoa(sp->arg->val.v_short)))
		|| (l_mod == hh && !(str_arg.str = ft_citoa(sp->arg->val.v_char))))
		return ((t_str_arg){ str : 0, is_freeable: 0, str_len : -1 });
	str_arg.is_freeable = true;
	str_arg.str_len = ft_strlen(str_arg.str);
	return (str_arg);
}

t_str_arg   ft_set_arg_u(t_str_part *sp)
{
	t_str_arg	str_arg;
	t_len_mod	l_mod;
	
	l_mod = sp->arg->len_mod;
	if ((l_mod == none && !(str_arg.str = ft_uitoa(sp->arg->val.v_uint)))
		|| (l_mod == l && !(str_arg.str = ft_ulitoa(sp->arg->val.v_ulint)))
		|| (l_mod == ll && !(str_arg.str = ft_ullitoa(sp->arg->val.v_ullint)))
		|| (l_mod == h && !(str_arg.str = ft_usitoa(sp->arg->val.v_ushort)))
		|| (l_mod == hh && !(str_arg.str = ft_ucitoa(sp->arg->val.v_uchar))))
		return ((t_str_arg){ str : 0, is_freeable: 0, str_len : -1 });
	str_arg.is_freeable = true;
	str_arg.str_len = ft_strlen(str_arg.str);
	return (str_arg);
}