/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:26:17 by msessa            #+#    #+#             */
/*   Updated: 2021/01/20 15:28:16 by msessa           ###   ########.fr       */
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

// static void		ft_set_strs_size(int *strs_size, char const *str, char c)
// {
// 	int		str_sel;
// 	int		str_sel_size;
// 	int		i;

// 	i = 0;
// 	str_sel = 0;
// 	str_sel_size = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != c)
// 			str_sel_size++;
// 		else if (str_sel_size != 0)
// 		{
// 			strs_size[str_sel] = str_sel_size + 1;
// 			str_sel++;
// 			str_sel_size = 0;
// 		}
// 		i++;
// 	}
// 	if (str_sel_size != 0)
// 		strs_size[str_sel] = str_sel_size + 1;
// }

static char		**ft_free_exit(char **res)
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
	return (0);
}

// static void		ft_set_strs_size(char **res, char const *str, char c)
// {
// 	int		str_sel;
// 	int		str_sel_size;
// 	int		i;

// 	i = 0;
// 	str_sel = 0;
// 	str_sel_size = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != c)
// 			str_sel_size++;
// 		else if (str_sel_size != 0)
// 		{
// 			if (!(res[str_sel] = malloc(sizeof(char) * (str_sel_size + 1))))
// 			{
// 				ft_free_exit(res);
// 				return ;
// 			}
// 			str_sel++;
// 			str_sel_size = 0;
// 		}
// 		i++;
// 	}
// 	if (str_sel_size != 0)
// 		if (!(res[str_sel] = malloc(sizeof(char) * (str_sel_size + 1))))
// 			ft_free_exit(res);
// }

static void		ft_set_strs_size(char **res, char const *str, char const c)
{
	char	**ores;
	int		str_size;

	ores = res;
	str_size = 0;
	while (*str)
	{
		if (*str != c)
			str_size++;
		else if (str_size != 0)
		{
			if (!(*res = malloc(sizeof(char) * (str_size + 1))))
			{
				ft_free_exit(ores);
				return ;
			}
			res++;
			str_size = 0;
		}
		str++;
	}
	if (str_size != 0)
		if (!(*res = malloc(sizeof(char) * (str_size + 1))))
			ft_free_exit(ores);
}

static void		ft_cpy_strs(char **strs, char const *str, char c)
{
	int		j;

	j = 0;
	while (*str)
	{
		if (*str != c)
			(*(strs))[j++] = *str;
		else if (j != 0)
		{
			(*(strs++))[j] = '\0';
			j = 0;
		}
		str++;
	}
	if (j != 0)
		(*(strs++))[j] = '\0';
	*(strs) = 0;
}

char			**ft_split(char const *s, char c)
{
	int		nb_strs;
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
		ft_set_strs_size(res, s, c);
		if (!res)
			return (0);
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
		ft_free_exit(res);
		repeating++;
	}
	return (0);
}
