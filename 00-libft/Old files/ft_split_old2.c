/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_old.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:26:17 by msessa            #+#    #+#             */
/*   Updated: 2021/01/20 14:02:53 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

static int		ft_nb_strs(char const *s, char c)
{
	int nb_s;

	if (!*s)
		return (0);
	s++;
	nb_s = 0;
	while (*s)
	{
		if (*s == c && *(s - 1) != c)
		{
			nb_s++;
			s++;
			if (!*s)
				break;
		}
		s++;
	}
	if (*(s - 1) != c)
		return (nb_s + 1);
	return (nb_s);
}

static void		ft_set_strs_size(int *strs_size, char const *str, char c)
{
	int		str_sel;
	int		str_sel_size;
	int		i;

	i = 0;
	str_sel = 0;
	str_sel_size = 0;
	while (str[i])
	{
		if (str[i] != c)
			str_sel_size++;
		else if (str_sel_size != 0)
		{
			strs_size[str_sel] = str_sel_size + 1;
			str_sel++;
			str_sel_size = 0;
		}
		i++;
	}
	if (str_sel_size != 0)
		strs_size[str_sel] = str_sel_size + 1;
}

static void		ft_cpy_strs(char **strs, char const *str, char c)
{
	int		str_sel;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str_sel = 0;
	while (str[i])
	{
		if (str[i] != c)
			strs[str_sel][j++] = str[i];
		else if (j != 0)
		{
			strs[str_sel][j] = '\0';
			str_sel++;
			j = 0;
		}
		i++;
	}
	if (j != 0)
		strs[str_sel++][j] = '\0';
	strs[str_sel] = 0;
}

static char		**ft_free_exit(char **res, int *strs_size)
{
	int i;

	if (res)
	{
		i = 0;
		while (res[i])
		{
			free(res[i]);
			i++;
		}
		free(res);
	}
	if (strs_size)
		free(strs_size);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	int		nb_strs;
	int		*strs_size;
	char	**res;

	if (!s)
		return (0);
	while (*s == c)
		s++;
	nb_strs = ft_nb_strs(s, c);
	if (!(res = malloc(sizeof(char *) * (nb_strs + 1))))
		return (0);
	if (nb_strs)
	{
		if (!(strs_size = malloc(sizeof(int) * (nb_strs))))
			return (ft_free_exit(res, 0));
		ft_set_strs_size(strs_size, s, c);
		while (--nb_strs >= 0)
			if (!(res[nb_strs] = malloc(sizeof(char) * strs_size[nb_strs])))
				return (ft_free_exit(res, strs_size));
		free(strs_size);
	}
	ft_cpy_strs(res, s, c);
	return (res);
}

int		main(void)
{
	int		fd;
	char	buf[3000001];
	int		buf_end;
	char	**res;
	int		repeating;
	// int		i;

	// i = 0;
	repeating = 0;
	while (repeating < 2000)
	{
		fd = open("split_test", O_RDONLY);
		buf_end = read(fd, buf, 3000000);
		close(fd);
		if (buf_end > 0)
		{
			buf[buf_end] = '\0';
			res = ft_split(buf, ' ');
			// if (res)
			// {
			// 	while (res[i])
			// 		i++;
			// 	printf("res size: %d\n", i);
			// }
		}
		ft_free_exit(res, 0);
		repeating++;
	}
	return (0);
}
