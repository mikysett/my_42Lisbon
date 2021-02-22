/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:08:41 by msessa            #+#    #+#             */
/*   Updated: 2021/02/18 19:07:16 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef enum	e_str_type
{
	string,
	argument
}				t_str_type;

typedef struct	s_str_part
{
	t_str_type			str_type;
	char				*str_start;
	char				*str_end;
	size_t				str_size;
	t_arg				*arg;
	struct s_str_part	*next;
}				t_str_part;

typedef struct	s_arg
{
	t_arg_type	type;
	t_val		val;
	t_flags		*flags;
	int			width;
	bool		w_as_arg;
	bool		precision_set;
	int			precision;
	bool		p_as_arg;
	t_len_mod	len_mod;
	char		conv;
}				t_arg;

typedef enum	e_arg_type
{
	tp_char,
	tp_uchar,
	tp_short,
	tp_ushort,
	tp_char_ptr,
	tp_ptr,
	tp_int,
	tp_lint,
	tp_llint,
	tp_uint,
	tp_ulint,
	tp_ullint,
	tp_wint,
	tp_wchar_ptr
}				t_arg_type;

typedef enum	e_flags
{
	none,
	minus,
	zero,
	hashtag,
	space,
	plus
}				t_flags;

typedef enum	e_len_mod
{
	none,
	l,
	ll,
	h,
	hh
}				t_len_mod;

typedef union	u_val
{
	char					v_char;
	unsigned char			v_uchar;
	short					v_short;
	unsigned short			v_ushort;
	char					*v_char_ptr;
	void					*v_ptr; // TO BE CHECKED
	int						v_int;
	long int				v_lint;
	long long int			v_llint;
	unsigned int			v_uint;
	unsigned long int		v_ulint;
	unsigned long long int	v_ullint;
	int						v_wint;
	wchar_t					*v_wchar_ptr;
}				t_val;

typedef struct	s_str_arg
{
	char	*str;
	int		str_len;
}				t_str_arg;



int			ft_printf(const char *format, ...);
t_str_part	**ft_set_str(char *format);
t_str_part	**ft_free_str_part(t_str_part **str_part);
char		*ft_set_arg_flags(t_arg *arg, char *str);
char		*ft_set_arg_width(t_arg *arg, char *str);
char		*ft_set_arg_precision(t_arg *arg, char *str);
char		*ft_set_arg_lenmod(t_arg *arg, char *str);
char		*ft_set_arg_conv(t_arg *arg, char *str);
char		*ft_set_arg_type(t_arg *arg, char *str);
bool		ft_is_conv(char c);
void		ft_sp_lstadd_back(t_str_part **lst, t_str_part *new);

#endif