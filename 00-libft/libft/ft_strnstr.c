/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:56:22 by msessa            #+#    #+#             */
/*   Updated: 2021/01/15 18:21:05 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little || !len)
		return ((char *)big);
	while (*big && len--)
	{
		if (*big == *little)
		{
			i = 1;
			while (big[i] && little[i] && i <= len && big[i] == little[i])
				i++;
			if (!little[i])
				return ((char *)big);
			if (i > len || !big[i])
				return (0);
		}
		big++;
	}
	return (0);
}
