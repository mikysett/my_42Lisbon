/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:08:41 by msessa            #+#    #+#             */
/*   Updated: 2021/02/17 17:44:26 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_arg
{
	size_t	format_len;
	t_type	type;
	t_val	value;
	char	conversion;

}				t_arg;

typedef enum	e_type
{
	tp_char,
	tp_char_ptr,
	tp_ptr,
	tp_int,
	tp_lint,
	tp_llint,
	tp_uint,
	tp_ulint,
	tp_ullint
}				t_type;

typedef union	u_val
{
	char					v_char;
	char					*v_char_ptr;
	void					*v_ptr; // TO BE CHECKED
	int						v_int;
	long int				v_lint;
	long long int			v_llint;
	unsigned int			v_uint;
	unsigned long int		v_ulint;
	unsigned long long int	v_ullint;
}				t_val;


int		ft_printf(const char *format, ...);

#endif