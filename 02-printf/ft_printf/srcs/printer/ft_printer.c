/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:39:12 by msessa            #+#    #+#             */
/*   Updated: 2021/03/04 17:49:35 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printer.h"

static void	ft_set_counter_arg(t_arg *arg, long long int print_result)
{
	if (arg->type == tp_char_ptr)
		*(arg->val.v_char_ptr) = (char)print_result;
	else if (arg->type == tp_short_ptr)
		*(arg->val.v_short_ptr) = (short)print_result;
	else if (arg->type == tp_int_ptr)
		*(arg->val.v_int_ptr) = (int)print_result;
	else if (arg->type == tp_lint_ptr)
		(*arg->val.v_lint_ptr) = (long int)print_result;
	else if (arg->type == tp_llint_ptr)
		*(arg->val.v_llint_ptr) = print_result;
}

t_str_arg	ft_set_str_arg(t_str_part *sp)
{
	if (sp->arg->conv == 'c')
		return (ft_set_arg_c(sp));
	else if (sp->arg->conv == 's')
		return (ft_set_arg_s(sp));
	else if (sp->arg->conv == 'p')
		return (ft_set_arg_p(sp));
	else if (sp->arg->conv == 'd' || sp->arg->conv == 'i')
		return (ft_set_arg_d(sp));
	else if (sp->arg->conv == 'u')
		return (ft_set_arg_u(sp));
	else if (sp->arg->conv == 'x' || sp->arg->conv == 'X')
		return (ft_set_arg_x(sp));
	else
		return ((t_str_arg){ .str = 0, .is_freeable = false, .str_len = -1 });
}

int			ft_printer(t_str_part *sp)
{
	long long int	print_count;
	t_str_arg		sa;

	print_count = 0;
	while (sp)
	{
		if (sp->str_type == string)
			print_count += write(1, sp->str_start, sp->str_size);
		else if (sp->str_type == argument)
		{
			sa = ft_set_str_arg(sp);
			if (sa.str_len == -1)
				return (-1);
			print_count = ft_print_arg(sp, sa, print_count);
			if (sa.is_freeable == true)
				free(sa.str);
			if (print_count < 0)
				return (-1);
		}
		else
			ft_set_counter_arg(sp->arg, print_count);
		sp = sp->next;
	}
	return (print_count);
}
