/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:19:55 by msessa            #+#    #+#             */
/*   Updated: 2021/01/16 13:27:53 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!(new_str = malloc(sizeof(char) * (s_len + 1))))
		return (0);
	while (*s)
		*new_str++ = *s++;
	*new_str = '\0';
	return (new_str - s_len);
}
