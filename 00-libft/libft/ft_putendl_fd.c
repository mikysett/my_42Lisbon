/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:09:09 by msessa            #+#    #+#             */
/*   Updated: 2021/01/18 13:25:30 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	c;
	size_t	s_len;

	if (!s)
		return ;
	s_len = ft_strlen(s);
	c = '\n';
	write(fd, s, s_len);
	write(fd, &c, 1);
}