# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 14:13:08 by msessa            #+#    #+#              #
#    Updated: 2021/02/24 16:48:46 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			ft_arg_param.c \
			ft_arg_utils.c \
			ft_flag_utils.c \
			ft_free.c \
			ft_list_str_part.c \
			ft_set_args.c \
			ft_set_str.c \
			printer/ft_print_arg.c \
			printer/ft_print_padding.c \
			printer/ft_printer.c \
			printer/set_arg_char.c \
			printer/set_arg_int.c \
			itoa/ft_citoa.c \
			itoa/ft_litoa.c \
			itoa/ft_llitoa.c \
			itoa/ft_sitoa.c \
			itoa/ft_ucitoa.c \
			itoa/ft_uitoa.c \
			itoa/ft_ulitoa.c \
			itoa/ft_ullitoa.c itoa/ft_usitoa.c \

BSRCS	:=	$(SRCS) \

OBJS	=	$(SRCS:.c=.o)

BOBJS	=	$(BSRCS:.c=.o)

NAME	=	libftprintf.a

DEPS	=	ft_printf.h itoa/ft_itoa.h

BDEPS	:=	$(DEPS) ft_printf.h itoa/ft_itoa.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra # -Werror

RM		=	rm -f

$(NAME):	$(DEPS) $(OBJS)
			ar rc $(NAME) $(OBJS)
			cd libft && $(MAKE)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) $(BOBJS)
			cd libft && $(MAKE) clean

fclean:		clean
			$(RM) $(NAME)
			cd libft && $(MAKE) fclean

re:			fclean all
			cd libft && $(MAKE) re

bonus:		$(BDEPS) $(BOBJS)
			ar rc $(NAME) $(BOBJS)

.PHONY:		all clean fclean re bonus