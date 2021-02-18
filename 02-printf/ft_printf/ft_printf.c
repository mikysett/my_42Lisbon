/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:09:10 by msessa            #+#    #+#             */
/*   Updated: 2021/02/17 18:07:53 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print_format(const char *format, char *o_format)
{
	int print_count;

	print_count = o_format - 1 - format;
	if (print_count > 0)
		write(1, format, print_count);
	return (print_count);
}

int				ft_printf(const char *format, ...)
{
	va_list ap;
	t_arg	*arg_sel;
	char	*o_format;
	int		print_count;

	va_start(ap, format);
	o_format = format;
	print_count = 0;
	while (o_format)
	{
		if (o_format == '%')
		{
			print_count += ft_print_format(format, o_format);
			if (!(arg_sel = ft_set_arg(o_format)))
				return (-1);
			print_count += ft_print_arg(arg_sel);
			o_format += arg_sel->format_len + 1;
			free(arg_sel);
		}
		else
			o_format++;
	}
	print_count += ft_print_format(format, o_format);
	va_end(ap);
	return (print_count);
}

int		main(void)
{

	return (0);
}
