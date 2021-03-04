/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:16:53 by msessa            #+#    #+#             */
/*   Updated: 2021/03/04 14:29:27 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printer.h"

char		*ft_get_padding(int len, char c)
{
	static char	*padding = 0;
	char		*running_pad;
	int			i;

	if (len == -1)
		return (padding = ft_free_padding(padding));
	i = 0;
	if (padding == 0 || ft_strlen(padding) < (size_t)len)
	{
		if (padding)
			free(padding);
		if (!(padding = malloc((sizeof(char) * (len + 1)))))
			return (0);
		padding[len] = '\0';
		while (i < len)
			padding[i++] = c;
	}
	else if (*padding != c)
	{
		running_pad = padding;
		while (*running_pad)
			*(running_pad++) = c;
	}
	return (padding);
}

bool		ft_print_padding(size_t len, bool is_zero)
{
	char	*padding;

	if (is_zero)
		padding = ft_get_padding(len, '0');
	else
		padding = ft_get_padding(len, ' ');
	if (!padding)
		return (false);
	write(1, padding, len);
	return (true);
}
