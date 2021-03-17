/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:19:41 by msessa            #+#    #+#             */
/*   Updated: 2021/03/17 16:05:36 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

bool		ft_get_arg_basic(va_list *ap, t_arg *arg)
{
	if (arg->type == tp_char)
		arg->val.v_char = (char)va_arg(*ap, int);
	else if (arg->type == tp_int)
		arg->val.v_int = va_arg(*ap, int);
	else if (arg->type == tp_char_ptr)
		arg->val.v_char_ptr = va_arg(*ap, char *);
	else if (arg->type == tp_lint)
		arg->val.v_lint = va_arg(*ap, long int);
	else
		return (false);
	return (true);
}

bool		ft_get_arg_unsigned(va_list *ap, t_arg *arg)
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

bool		ft_get_arg_mix(va_list *ap, t_arg *arg)
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

bool		ft_get_arg_n(va_list *ap, t_arg *arg)
{
	if (arg->type == tp_int_ptr)
		arg->val.v_int_ptr = va_arg(*ap, int *);
	else if (arg->type == tp_lint_ptr)
		arg->val.v_lint_ptr = va_arg(*ap, long int *);
	else if (arg->type == tp_llint_ptr)
		arg->val.v_llint_ptr = va_arg(*ap, long long int *);
	else if (arg->type == tp_short_ptr)
		arg->val.v_short_ptr = va_arg(*ap, short *);
	else if (arg->type == tp_char_ptr)
		arg->val.v_char_ptr = va_arg(*ap, char *);
	else
		return (false);
	return (true);
}
