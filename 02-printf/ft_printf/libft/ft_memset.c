/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:45:41 by msessa            #+#    #+#             */
/*   Updated: 2021/01/15 15:46:02 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void *res;

	c = (unsigned char)c;
	res = s;
	while (n-- > 0)
		*((unsigned char *)s++) = c;
	return (res);
}
