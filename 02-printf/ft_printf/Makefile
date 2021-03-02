# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 14:13:08 by msessa            #+#    #+#              #
#    Updated: 2021/03/02 17:51:25 by msessa           ###   ########.fr        #
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
			printer/ft_set_arg_char.c \
			printer/ft_set_arg_int.c \
			number_printers/ft_set_hex.c \
			number_printers/ft_set_hex_utils.c \
			number_printers/ft_llitoa_len.c \
			number_printers/ft_ullitoa_len.c \

BSRCS	:=	$(SRCS) \

TSRCS	:=	$(SRCS) main.c

OBJS	=	$(SRCS:.c=.o)

TOBJS	:=	$(TSRCS:.c=.o)

BOBJS	=	$(BSRCS:.c=.o)

NAME	=	libftprintf.a

DEPS	=	ft_printf.h \
			ft_my_types.h \
			number_printers/ft_number_printers.h \
			printer/ft_printer.h \
			libft/libft.h \

BDEPS	:=	$(DEPS)

CC		=	gcc

CFLAGS	=	-g -Wall -Wextra -Werror

RM		=	rm -f

$(NAME):	$(DEPS) $(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

test:		$(DEPS) $(TOBJS)
			$(CC) $(CFLAGS) -fsanitize=address $(TOBJS) -o test

clean:
			$(RM) $(OBJS)
			$(RM) $(BOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		$(BDEPS) $(BOBJS)
			ar rc $(NAME) $(BOBJS)

.PHONY:		all clean fclean re bonus