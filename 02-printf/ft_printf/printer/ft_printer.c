/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:52:54 by msessa            #+#    #+#             */
/*   Updated: 2021/02/24 16:52:54 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"

static void	ft_set_counter_arg(t_arg *arg, long long int print_result)
{
	if (arg->type == tp_char)
		arg->val.v_char = (char) print_result;
	else if (arg->type == tp_short)
		arg->val.v_short = (short) print_result;
	else if (arg->type == tp_int)
		arg->val.v_int = (int) print_result;
	else if (arg->type == tp_lint)
		arg->val.v_lint =  (long int) print_result;
	else if (arg->type == tp_llint)
		arg->val.v_llint = print_result;
}

t_str_arg   ft_set_str_arg(t_str_part *sp)
{
	if (sp->arg->conv == 'c')
		return (ft_set_arg_c(sp));
	else if (sp->arg->conv == 's')
		return (ft_set_arg_s(sp));
	else if (sp->arg->conv == 'p')
		return (ft_set_arg_p(sp));
	else if (sp->arg->conv == 'd' || sp->arg->conv == 'i'
		|| sp->arg->conv == 'n')
		return (ft_set_arg_d(sp));
	else if (sp->arg->conv == 'u')
		return (ft_set_arg_u(sp));
	else if (sp->arg->conv == 'x' || sp->arg->conv == 'X')
		return (ft_set_arg_x(sp));
	// else if (sp->arg->conv == 'n')
	// 	return (ft_set_arg_n(sp));
	// else if (sp->arg->conv == 'f')
	// 	return (ft_set_arg_f(sp));
	// else if (sp->arg->conv == 'g')
	// 	return (ft_set_arg_g(sp));
	// else if (sp->arg->conv == 'e')
	// 	return (ft_set_arg_e(sp));
	else
		return ((t_str_arg){ .str = 0, .is_freeable = false, .str_len = -1 });
}

int			ft_printer(t_str_part *sp)
{
	long long int	print_count;
	long long int	print_result;
	t_str_arg	sa;

	print_count = 0;
	while (sp)
	{
		if (sp->str_type == string)
			print_count += write(1, sp->str_start, sp->str_size);
		else // if (sp->str_type == argument)
		{
			// printf("\nconv: %c, print_result: %lld\n", sp->arg->conv, print_count);
			if (sp->str_type == print_counter)
				ft_set_counter_arg(sp->arg, print_count);
			sa = ft_set_str_arg(sp);
			if (sa.str_len == -1)
				return (-1);
			print_result = ft_print_arg(sp, sa);
			if (sa.is_freeable == true)
				free(sa.str);
			if (print_result < 0)
				return (-1);
			print_count += print_result;
		}
		// else // if (sp->str_type == print_counter)
		// 	print_count += ft_set_counter_arg(sp, print_result);
		sp = sp->next;
	}
	return (print_count);
}