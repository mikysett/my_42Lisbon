/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:16:49 by msessa            #+#    #+#             */
/*   Updated: 2021/02/24 20:37:38 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printer.h"

int		ft_print_arg(t_str_part *sp, t_str_arg str_arg)
{
	int padding_len;

	padding_len = sp->arg->width - str_arg.str_len;
	if (padding_len > 0)
	{
		if (!sp->arg->flags[minus])
		{
			if (!ft_print_padding(padding_len, sp->arg->flags[zero]))
				return (-1);
			if (str_arg.str_len)
				write(1, str_arg.str, str_arg.str_len);
		}
		else
		{
			if (str_arg.str_len)
				write(1, str_arg.str, str_arg.str_len);
			if (!ft_print_padding(padding_len, false))
				return (-1);
		}
		return (padding_len + str_arg.str_len);
	}
	if (str_arg.str_len)
		write(1, str_arg.str, str_arg.str_len);
	return (str_arg.str_len);
}