/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:31:40 by msessa            #+#    #+#             */
/*   Updated: 2021/02/18 17:45:13 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_free_arg(t_arg *arg)
{
	if (!arg)
		return (0);
	if (arg->flags)
		free(arg->flags);
	free(arg);
}

t_str_part	**ft_free_str_part(t_str_part **str_part)
{
	t_str_part	*next;

	if (!str_part)
		return (0);
	while (*str_part)
	{
		if ((*str_part)->str_type == argument)
			ft_free_arg((*str_part)->arg);
		next = (*str_part)->next;
		free(*str_part);
		*str_part = next;
	}
	free(str_part);
}