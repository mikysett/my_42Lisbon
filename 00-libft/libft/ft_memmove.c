/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:32:01 by msessa            #+#    #+#             */
/*   Updated: 2021/01/15 16:12:03 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	buff[n];
	size_t			i;
	
	if (dest == src)
		return (dest);
	i = 0;
	while (i < n)
	{
		buff[i] = *((unsigned char *)src + i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = buff[i];
		i++;
	}
	return (dest);
}
