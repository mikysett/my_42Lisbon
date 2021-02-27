/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:19:41 by msessa            #+#    #+#             */
/*   Updated: 2021/02/27 13:12:44 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool		get_w(t_str_part *sp, int size)
{
	if (size < 0)
	{
		sp->arg->flags[minus] = true;
		sp->arg->width = -size;
	}
	else
		sp->arg->width = size;
	return (true);
}

static bool		get_p(t_arg *arg, int size)
{
	arg->precision = size;
	return (true);
}

bool			ft_set_args(va_list ap, t_str_part *sp)
{
	va_list ap2;
	t_arg	*arg;

	va_copy(ap2, ap);
	while (sp)
	{
		if (sp->str_type == argument)
		{
			arg = sp->arg;
			if ((arg->w_as_arg && !get_w(sp, va_arg(ap2, int)))
				|| (arg->p_as_arg && !get_p(arg, va_arg(ap2, int))))
				return (false);
			if (arg->type == tp_char)
				arg->val.v_char = va_arg(ap2, int);
			else if (arg->type == tp_uchar)
				arg->val.v_uchar = (unsigned char)va_arg(ap2, int);
			else if (arg->type == tp_wint)
				arg->val.v_wint = va_arg(ap2, wchar_t);
			else if (arg->type == tp_short)
				arg->val.v_short = (short)va_arg(ap2, int);
			else if (arg->type == tp_ushort)
				arg->val.v_ushort = (unsigned short)va_arg(ap2, int);
			else if (arg->type == tp_char_ptr)
				arg->val.v_char_ptr = va_arg(ap2, char *);
			else if (arg->type == tp_ptr)
				arg->val.v_ptr = va_arg(ap2, void *);
			else if (arg->type == tp_int || arg->type == tp_wint)
				arg->val.v_int = va_arg(ap2, int);
			else if (arg->type == tp_lint)
				arg->val.v_lint = va_arg(ap2, long int);
			else if (arg->type == tp_llint)
				arg->val.v_llint = va_arg(ap2, long long int);
			else if (arg->type == tp_uint)
				arg->val.v_uint = va_arg(ap2, unsigned int);
			else if (arg->type == tp_ulint)
				arg->val.v_ulint = va_arg(ap2, unsigned long int);
			else if (arg->type == tp_ullint)
				arg->val.v_ullint = va_arg(ap2, unsigned long long int);
			else if (arg->type == tp_wchar_ptr)
				arg->val.v_wchar_ptr = va_arg(ap2, wchar_t *);
		}
		sp = sp->next;
	}
	va_end(ap2);
	return (true);
}