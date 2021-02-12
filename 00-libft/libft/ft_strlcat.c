/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:13:38 by msessa            #+#    #+#             */
/*   Updated: 2021/01/15 17:45:54 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (size-- == 0)
		return (dst_len + src_len);
	while (*src && size != 0)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (dst_len + src_len);
}

// size_t
// ft_strlcat(char *dst, const char *src, size_t dsize)
// {
// 	const char *odst = dst;
// 	const char *osrc = src;
// 	size_t n = dsize;
// 	size_t dlen;

// 	/* Find the end of dst and adjust bytes left but don't go past end. */
// 	while (n-- != 0 && *dst != '\0')
// 		dst++;
// 	dlen = dst - odst;
// 	n = dsize - dlen;

// 	if (n-- == 0)
// 		return(dlen + ft_strlen(src));
// 	while (*src != '\0') {
// 		if (n != 0) {
// 			*dst++ = *src;
// 			n--;
// 		}
// 		src++;
// 	}
// 	*dst = '\0';

// 	return(dlen + (src - osrc));	/* count does not include NUL */
// }