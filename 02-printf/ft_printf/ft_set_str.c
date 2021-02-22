/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:20:28 by msessa            #+#    #+#             */
/*   Updated: 2021/02/18 17:48:08 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool		ft_add_str(t_str_part **str_part, char *format, char *o_format)
{
	t_str_part *new_str;

	if (!(new_str = malloc(sizeof(t_str_part))))
		return (false);
	new_str->str_type = string;
	new_str->str_start = format;
	new_str->str_end = o_format;
	new_str->str_size = o_format - format;
	ft_sp_lstadd_back(str_part, new_str);
	return (true);
}

static char		*ft_add_arg(t_str_part **str_part, char *o_format)
{
	t_str_part *new_arg;

	if (!(new_arg = malloc(sizeof(t_str_part))))
		return (0);
	new_arg->str_type = argument;
	if ((o_format = ft_set_arg_flags(new_arg, o_format))
		&& (o_format = ft_set_arg_width(new_arg, o_format))
		&& (o_format = ft_set_arg_precision(new_arg, o_format))
		&& (o_format = ft_set_arg_lenmod(new_arg, o_format))
		&& (o_format = ft_set_arg_conv(new_arg, o_format))
		&& (o_format = ft_set_arg_type(new_arg, o_format)))
		;
	ft_sp_lstadd_back(str_part, new_arg);
	return (o_format);
}
static char		*ft_add_percent(t_str_part **str_part, char *o_format)
{
	t_str_part *new_str;

	if (!(new_str = malloc(sizeof(t_str_part))))
		return (0);
	new_str->str_type = string;
	new_str->str_start = o_format;
	new_str->str_end = o_format + 1;
	ft_sp_lstadd_back(str_part, new_str);
	return (o_format + 2);
}

static char		*ft_add_str_part(t_str_part **str_part, char *format, char *o_format)
{
	if (format != o_format)
		if (!ft_add_str(str_part, format, o_format))
			return (0);
	if (*o_format == '%')
	{
		if (*(o_format + 1) != '%')
			o_format = ft_add_arg(str_part, o_format + 1);
		else
			o_format = ft_add_percent(str_part, o_format);
	}
	return (o_format);
}

t_str_part		**ft_set_str(char *format)
{
	t_str_part	**str_part;
	char		*o_format;

	o_format = format;
	if (!(str_part = malloc(sizeof(t_str_part *))))
		return (0);
	*str_part = 0;
	while (*o_format)
	{
		if (*o_format == '%')
		{
			if (!(o_format = ft_add_str_part(str_part, format, o_format)))
				return (ft_free_str_part(str_part));
			format = o_format;
		}
		else
			o_format++;
	}
	if (format != o_format && !ft_add_str_part(str_part, format, o_format))
		return (ft_free_str_part(str_part));
	return (str_part);
}
