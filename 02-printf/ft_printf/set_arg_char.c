/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:49:02 by msessa            #+#    #+#             */
/*   Updated: 2021/02/23 21:10:23 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str_arg   ft_set_arg_c(t_str_part *sp)
{
	t_str_arg	str_arg;

	if (ft_isprint(sp->arg->val.v_char))
	{
		if(!(str_arg.str = malloc(sizeof(char) * 2)))
			str_arg.str_len = -1;
		else
			str_arg.str_len = 1;
		*(str_arg.str) = sp->arg->val.v_char;
		*(str_arg.str + 1) = '\0';
	}
	else
		str_arg.str_len = 0;
	return (str_arg);
}

t_str_arg   ft_set_arg_s(t_str_part *sp)
{


}