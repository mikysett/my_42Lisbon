/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:09:10 by msessa            #+#    #+#             */
/*   Updated: 2021/02/18 18:23:55 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_str_part	**str_part;
	int			print_count;

	if (!(str_part = ft_set_str(format)))
		return (-1);
	va_start(ap, format);
	if (!ft_set_args(ap, str_part))
		return (-1);
	va_end(ap);
	print_count = ft_print_str_part(str_part);
	ft_free_str_part(str_part);
	return (print_count);
}

int		main(void)
{
	return (0);
}
