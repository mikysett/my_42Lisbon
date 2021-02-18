# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 14:13:08 by msessa            #+#    #+#              #
#    Updated: 2021/02/18 11:33:56 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			ft_set_str.c \
			ft_free_str_part.c \
			ft_arg.c \

BSRCS	:=	$(SRCS) \

OBJS	=	$(SRCS:.c=.o)

BOBJS	=	$(BSRCS:.c=.o)

NAME	=	libftprintf.a

DEPS	=	printf.h

BDEPS	:=	$(DEPS) printf.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

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