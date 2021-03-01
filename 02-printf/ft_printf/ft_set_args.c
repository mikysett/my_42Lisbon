/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:19:41 by msessa            #+#    #+#             */
/*   Updated: 2021/03/01 16:37:45 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_get_arg_width(t_str_part *sp, int size)
{
	if (size < 0)
	{
		sp->arg->flags[minus] = true;
		sp->arg->width = -size;
	}
	else
		sp->arg->width = size;
}

static bool		ft_get_arg_unsigned(va_list *ap, t_arg *arg)
{
	if (arg->type == tp_uint)
		arg->val.v_uint = va_arg(*ap, unsigned int);
	else if (arg->type == tp_ulint)
		arg->val.v_ulint = va_arg(*ap, unsigned long int);
	else if (arg->type == tp_ullint)
		arg->val.v_ullint = va_arg(*ap, unsigned long long int);
	else if (arg->type == tp_ushort)
		arg->val.v_ushort = (unsigned short)va_arg(*ap, int);
	else if (arg->type == tp_uchar)
		arg->val.v_uchar = (unsigned char)va_arg(*ap, int);
	else
		return (false);
	return (true);
}

static bool		ft_get_arg_mix(va_list *ap, t_arg *arg)
{
	if (arg->type == tp_llint)
		arg->val.v_llint = va_arg(*ap, long long int);
	else if (arg->type == tp_ptr)
		arg->val.v_ptr = va_arg(*ap, void *);
	else if (arg->type == tp_short)
		arg->val.v_short = (short)va_arg(*ap, int);
	else if (arg->type == tp_wint)
		arg->val.v_wint = va_arg(*ap, wchar_t);
	else if (arg->type == tp_wchar_ptr)
		arg->val.v_wchar_ptr = va_arg(*ap, wchar_t *);
	else
		return (false);
	return (true);
}

bool			ft_set_args(va_list *ap, t_str_part *sp)
{
	t_arg	*arg;

	while (sp)
	{
		if (sp->str_type == argument)
		{
			arg = sp->arg;
			if (arg->w_as_arg)
				ft_get_arg_width(sp, va_arg(*ap, int));
			if (arg->p_as_arg)
				sp->arg->precision = va_arg(*ap, int);
			if (arg->type == tp_char)
				arg->val.v_char = (char)va_arg(*ap, int);
			else if (arg->type == tp_int)
				arg->val.v_int = va_arg(*ap, int);
			else if (arg->type == tp_char_ptr)
				arg->val.v_char_ptr = va_arg(*ap, char *);
			else if (arg->type == tp_lint)
				arg->val.v_lint = va_arg(*ap, long int);
			else if (!ft_get_arg_unsigned(ap, arg))
				ft_get_arg_mix(ap, arg);
		}
		sp = sp->next;
	}
	return (true);
}
