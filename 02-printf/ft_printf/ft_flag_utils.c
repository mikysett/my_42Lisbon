/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:41:19 by msessa            #+#    #+#             */
/*   Updated: 2021/02/24 16:44:21 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_convert_flag(char c)
{
	if (c == '#')
		return (hashtag);
	if (c == '0')
		return (zero);
	if (c == '-')
		return (minus);
	if (c == ' ')
		return (space);
	if (c == '+')
		return (plus);
	return (flags_none);
}
