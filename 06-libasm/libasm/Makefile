# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 11:32:44 by msessa            #+#    #+#              #
#    Updated: 2021/05/06 16:32:18 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

LIBFT	=	libft

HEADERS	=	headers

DIR_S	=	srcs

DIR_O	=	obj

O_SRCS	:=	

SRCS	:=	$(O_SRCS)

B_SRCS	:=	$(O_SRCS)

OBJS	:= $(SRCS:%.c=$(DIR_O)/%.o)

BOBJS	:= $(B_SRCS:%.c=$(DIR_O)/%.o)

SUB_DIR_O := $(shell find $(DIR_S) -type d)
SUB_DIR_O := $(SUB_DIR_O:%=$(DIR_O)/%)

DEPS	=	

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

INCLUDES	= -I/libft/ -I/headers/

$(DIR_O)/%.o: %.c
			@mkdir -p $(DIR_O)
			@mkdir -p $(SUB_DIR_O)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME):	$(DEPS) $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) $(BOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		$(DEPS) $(BOBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(BOBJS) $(LIBS)

.PHONY:		all clean fclean cubclean re bonus
