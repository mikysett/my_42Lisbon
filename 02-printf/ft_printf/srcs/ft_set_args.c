/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:19:41 by msessa            #+#    #+#             */
/*   Updated: 2021/03/17 16:39:43 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
			if (!ft_get_arg_basic(ap, arg)
				&& !ft_get_arg_unsigned(ap, arg) && !ft_get_arg_mix(ap, arg))
				return (false);
		}
		else if (sp->str_type == print_counter && !ft_get_arg_n(ap, sp->arg))
			return (false);
		sp = sp->next;
	}
	return (true);
}
