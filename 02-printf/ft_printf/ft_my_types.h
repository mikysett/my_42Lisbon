/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:08:41 by msessa            #+#    #+#             */
/*   Updated: 2021/03/02 15:09:09 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MY_TYPES_H
# define FT_MY_TYPES_H
# include <stdlib.h>
# include <stdbool.h>
# define NB_FLAGS 6

typedef enum	e_str_type
{
	string,
	argument,
	print_counter
}				t_str_type;

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
	minus,
	zero,
	hashtag,
	space,
	plus,
	flags_none
}				t_flags;

typedef enum	e_len_mod
{
	lm_none,
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
	void					*v_ptr;
	int						v_int;
	long int				v_lint;
	long long int			v_llint;
	unsigned int			v_uint;
	unsigned long int		v_ulint;
	unsigned long long int	v_ullint;
	wchar_t					v_wint;
	wchar_t					*v_wchar_ptr;
}				t_val;

typedef struct	s_arg
{
	t_arg_type	type;
	t_val		val;
	bool		flags[NB_FLAGS];
	int			width;
	bool		w_as_arg;
	bool		precision_set;
	int			precision;
	bool		p_as_arg;
	t_len_mod	len_mod;
	char		conv;
}				t_arg;

typedef struct	s_str_part
{
	t_str_type			str_type;
	char				*str_start;
	char				*str_end;
	size_t				str_size;
	t_arg				*arg;
	struct s_str_part	*next;
}				t_str_part;

typedef struct	s_str_arg
{
	bool	is_freeable;
	char	*str;
	int		str_len;
}				t_str_arg;

#endif
