/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:28:06 by msessa            #+#    #+#             */
/*   Updated: 2021/03/01 18:07:10 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char *i;

	i = s;
	while (*i)
		i++;
	return (i - s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_len;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (*src && --size > 0)
			*(dst++) = *(src++);
		*dst = '\0';
	}
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*odst;
	size_t	dst_len;
	size_t	src_len;

	odst = dst;
	while (*dst && size != 0)
	{
		dst++;
		size--;
	}
	dst_len = dst - odst;
	src_len = ft_strlen(src);
	if (size == 0)
		return (dst_len + src_len);
	size--;
	while (*src && size != 0)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
