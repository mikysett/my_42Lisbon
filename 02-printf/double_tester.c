#include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# define NB_FLAGS 5

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
	tp_double,
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
	void					*v_ptr; // TO BE CHECKED
	int						v_int;
	long int				v_lint;
	long long int			v_llint;
	unsigned int			v_uint;
	unsigned long int		v_ulint;
	unsigned long long int	v_ullint;
	double					v_double;
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

typedef struct	s_double
{
	int				neg;
	int				exponent;
	int				int_digits;
	int				fract_digits;
}				t_double;

static int		ft_get_int_digits(double n, int int_precision)
{
	int				int_digits;
	long long int	buf;

	buf = (long long)n;
	int_digits = 0;
	if (int_precision == -1)
		while (buf != 0)
		{
			buf /= 10;
			int_digits++;
		}
	else
		while (buf != 0 && int_precision--)
		{
			buf /= 10;
			int_digits++;
		}
	return (int_digits);
}

static int		ft_get_fract_digits(double n, int precision)
{
	int			fract_digits;
	long long	buf;
	int			i;

	i = 0;
	n -= (long long)n;
	fract_digits = 0;
	while (precision--)
	{
		n *= 10;
		buf = (long long)n;
		n -= buf;
		i++;
		if (buf != 0)
			fract_digits = i;
	}
	return (fract_digits);
}

// static int		ft_get_fract_digits(double n, int precision)
// {
// 	int			fract_digits;
// 	long long	magnitude;
// 	long long	buf;
// 	int			i;

// 	printf("n: %.30f\n", n);
// 	if (!precision)
// 		return (0);
// 	i = 0;
// 	magnitude = 1;
// 	while (i++ < precision)
// 		magnitude *= 10;
// 	buf = (long long)((n - (long long)n) * magnitude);
// 	if (!buf)
// 		return (0);
// 	fract_digits = precision;
// 	printf("buf: %lld\n", buf);
// 	while (buf != 0 && !(buf % 10))
// 	{
// 		fract_digits--;
// 		buf /= 10;
// 	}
// 	return (fract_digits);
// }

static t_double		ft_get_exponent(t_double nb, double n)
{
	int			expo_neg;

	expo_neg = nb.int_digits == 0 ? 1 : 0;
	if (!expo_neg)
		nb.exponent = nb.int_digits - 1;
	else
	{
		nb.exponent = 0;
		n -= (long long)n;
		if (nb.neg)
			while (n > -1)
			{
				n *= 10;
				nb.exponent++;
			}
		else
			while (n < 1)
			{
				n *= 10;
				nb.exponent++;
			}
		nb.exponent *= -1;
	}
	return (nb);
}

static t_double	ft_set_double(t_arg *arg, double n, int precision)
{
	t_double	res;

	res.neg = n < 0 ? 1 : 0;
	if (arg->conv == 'e')
	{
		res.int_digits = ft_get_int_digits(n, precision);
		precision -= res.int_digits;
	}
	else
		res.int_digits = ft_get_int_digits(n, -1);
	if (precision)
		res.fract_digits = ft_get_fract_digits(n, precision);
	else
		res.fract_digits = 0;
	res = ft_get_exponent(res, n);
	printf("num: %f precision: %d neg: %d int_digits: %d fract_digits: %d exponent: %d\n",
		n, precision, res.neg, res.int_digits, res.fract_digits, res.exponent);
	return (res);
}

int			main(void)
{
	t_double 	test;
	t_val		nb;
	t_arg		*test_arg;

	test_arg = malloc(sizeof(t_arg));
	test_arg->conv = 'f';
	nb.v_double = -765.345555555555;
	printf("number  : %f\n", (double)23);
	printf("number  : %030f|\n", -0.345555555555);
	printf("number  : %030.f|\n", -0.345555555555);
	printf("number  : %-030f|\n", 0.345555555555);
	printf("number  : %-030.f|\n", 0.345555555555);
	printf("number  : %.f\n", 0.345555555555);
	printf("number  : %.f\n", 0.345555555555);
	printf("number  : %f\n", -0.345555555555);
	printf("number  : %.f\n", -0.345555555555);
	printf("number  : %.f\n", -0.345555555555);
	printf("number  : %.f\n", (double)0);
	printf("number  : %g\n", 0.345555555555);
	printf("number  : %.g\n", 0.345555555555);
	printf("number  : %.3g\n", 0.345555555555);
	printf("number  : %g\n", -0.345555555555);
	printf("number  : %.g\n", -0.345555555555);
	printf("number  : %.g\n", -0.345555555555);
	printf("number  : %.g\n", (double)0);
	printf("number  : %e\n", 0.345555555555);
	printf("number  : %.e\n", 0.345555555555);
	printf("number  : %.3e\n", 0.345555555555);
	printf("number  : %e\n", 0.345);
	printf("number  : %.e\n", 0.345);
	printf("number  : %.3e\n", 0.345);
	printf("number  : %e\n", -345e120);
	printf("number  : %f\n", -345e120);
	printf("number  : %e\n", -0.345555555555);
	printf("number  : %.e\n", -0.345555555555);
	printf("number  : %.e\n", -0.345555555555);
	printf("number  : %g\n", 3e-5);
	printf("number  : %#g\n", 3e-5);
	printf("number  : %e\n", 3e-5);
	printf("number  : %e\n", (double)3);
	printf("number  : %#e\n", 3e-5);
	printf("number  : %lld\n", (long long)nb.v_double);
	ft_set_double(test_arg, 34e-3, 6);
	ft_set_double(test_arg, 34e-3, 0);
	ft_set_double(test_arg, 34e-3, 2);
	ft_set_double(test_arg, 34e3, 6);
	ft_set_double(test_arg, 34e3, 0);
	ft_set_double(test_arg, 34e3, 2);
	ft_set_double(test_arg, 34.5673212121e3, 6);
	ft_set_double(test_arg, 34.5673212121e3, 0);
	ft_set_double(test_arg, 34.5673212121e3, 2);
	ft_set_double(test_arg, 34.5e0, 19);
	ft_set_double(test_arg, -34e-3, 6);
	ft_set_double(test_arg, -34e-3, 0);
	ft_set_double(test_arg, -34e-3, 2);
	ft_set_double(test_arg, -34e3, 6);
	ft_set_double(test_arg, -34e3, 0);
	ft_set_double(test_arg, -34e3, 2);
	ft_set_double(test_arg, -34.5673212121e3, 6);
	ft_set_double(test_arg, -34.5673212121e3, 0);
	ft_set_double(test_arg, -34.5673212121e3, 2);
	ft_set_double(test_arg, -34.5e0, 19);
	ft_set_double(test_arg, 9999999999.99999999e0, 5);
	ft_set_double(test_arg, 5555555.5555555555, 5);
	ft_set_double(test_arg, 2e53, 40);
	ft_set_double(test_arg, 99999999999999999999e53, 40);
	ft_set_double(test_arg, 9999999999999999999999999999999999999999999999999e53, 40);
	ft_set_double(test_arg, 9999999999999999999999999999999999999999999999999999999999999999999999999999999e53, 40);
	ft_set_double(test_arg, 9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999e53, 40);
	ft_set_double(test_arg, 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999e53, 40);
	return (0);
}