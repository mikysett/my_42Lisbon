/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:49:02 by msessa            #+#    #+#             */
/*   Updated: 2021/02/24 20:39:45 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"

t_str_arg   ft_set_arg_c(t_str_part *sp)
{
	t_str_arg	str_arg;

	if (ft_isprint(sp->arg->val.v_char))
	{
		str_arg.str_len = 1;
		*(str_arg.char_str) = sp->arg->val.v_char;
		*(str_arg.char_str + 1) = '\0';
		str_arg.str = str_arg.char_str;
	}
	else
		str_arg.str_len = 0;
	str_arg.is_freeable = false;
	return (str_arg);
}

t_str_arg   ft_set_arg_s(t_str_part *sp)
{
	int			str_size;
	t_str_arg	str_arg;

	str_arg.str = sp->arg->val.v_char_ptr;
	if (sp->arg->precision_set)
	{
		str_size = 0;
		while (str_arg.str[str_size] && str_size < sp->arg->precision)
			str_size++;
		str_arg.str_len = str_size;
	}
	else
		str_arg.str_len = ft_strlen(str_arg.str);
	str_arg.is_freeable = false;
	return (str_arg);
}