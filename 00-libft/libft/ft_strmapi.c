/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:26:17 by msessa            #+#    #+#             */
/*   Updated: 2021/01/18 11:37:16 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			s_len;
	char			*res;
	unsigned int	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	i = 0;
	if (!(res = malloc(sizeof(char) * s_len + 1)))
		return (0);
	while (i < s_len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}