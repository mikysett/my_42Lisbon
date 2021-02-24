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

int			ft_print_str(t_str_part *sp)
{
	return (write(1, sp->str_start, sp->str_size));
}

t_str_arg   ft_set_str_arg(t_str_part *sp)
{
	if (sp->arg->conv == 'c')
		return (ft_set_arg_c(sp));
	else if (sp->arg->conv == 's')
		return (ft_set_arg_s(sp));
	// else if (sp->arg->conv == 'p')
	// 	return (ft_set_arg_p(sp));
	else if (sp->arg->conv == 'd' || sp->arg->conv == 'i')
		return (ft_set_arg_d(sp));
	else if (sp->arg->conv == 'u')
		return (ft_set_arg_u(sp));
	// else if (sp->arg->conv == 'x' || sp->arg->conv == 'X')
	// 	return (ft_set_arg_x(sp));
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
	int			print_count;
	int			print_result;
	t_str_arg	str_arg;

	print_count = 0;
	while (sp)
	{
		if (sp->str_type == string)
			print_result = ft_print_str(sp);
		else
		{
			str_arg = ft_set_str_arg(sp);
			if (str_arg.str_len == -1)
				return (-1);
			print_result = ft_print_arg(sp, str_arg);
			if (str_arg.is_freeable)
				free(str_arg.str);
		}
		if (print_result < 0)
			return (-1);
		print_count += print_result;
		sp = sp->next;
	}
	return (print_count);
}