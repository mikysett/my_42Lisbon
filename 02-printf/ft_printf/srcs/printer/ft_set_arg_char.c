/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_arg_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:49:02 by msessa            #+#    #+#             */
/*   Updated: 2021/03/17 16:03:47 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printer.h"

static char	*ft_get_null(char conv)
{
	static char null_str[7] = "(null)";
	static char nil_str[6] = "0x0";

	if (conv == 's')
		return (null_str);
	else
		return (nil_str);
	return (null_str);
}

t_str_arg	ft_set_arg_c(t_str_part *sp)
{
	t_str_arg	str_arg;

	str_arg.str_len = 1;
	if (sp->arg->len_mod == l)
		str_arg.str = (char *)&(sp->arg->val.v_wint);
	else
		str_arg.str = &(sp->arg->val.v_char);
	str_arg.is_freeable = false;
	return (str_arg);
}

t_str_arg	ft_set_arg_s(t_str_part *sp)
{
	int			str_size;
	t_arg		*arg;
	t_str_arg	sa;

	arg = sp->arg;
	if (arg->precision_set == true && arg->precision < 0)
		arg->precision_set = false;
	if (!arg->val.v_char_ptr)
		sa.str = ft_get_null(arg->conv);
	else
		sa.str = arg->val.v_char_ptr;
	if (arg->precision_set)
	{
		str_size = 0;
		while (sa.str[str_size] && str_size < arg->precision)
			str_size++;
		sa.str_len = str_size;
	}
	else
		sa.str_len = ft_strlen(sa.str);
	sa.is_freeable = false;
	return (sa);
}
