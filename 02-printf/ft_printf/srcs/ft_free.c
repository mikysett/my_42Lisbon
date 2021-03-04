/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:31:40 by msessa            #+#    #+#             */
/*   Updated: 2021/03/04 14:22:47 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_free_arg(t_arg *arg)
{
	if (!arg)
		return ;
	free(arg);
}

char		*ft_free_padding(char *padding)
{
	if (padding)
		free(padding);
	return (0);
}

t_str_part	**ft_free_str_part(t_str_part **str_part)
{
	t_str_part	*next;

	if (!str_part)
		return (0);
	while (*str_part)
	{
		if ((*str_part)->str_type != string)
			ft_free_arg((*str_part)->arg);
		next = (*str_part)->next;
		free(*str_part);
		*str_part = next;
	}
	free(str_part);
	return (0);
}

void		ft_free_one_str_arg(t_str_part *str_part)
{
	if (!str_part)
		return ;
	ft_free_arg(str_part->arg);
	free(str_part);
}
