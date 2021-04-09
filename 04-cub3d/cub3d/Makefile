# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 11:32:44 by msessa            #+#    #+#              #
#    Updated: 2021/04/09 11:18:31 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

LIBFT	=	libft

MINILIBX	=	minilibx

HEADERS	=	headers

DIR_S	=	srcs

DIR_O	=	obj

SRCS	:= $(shell find $(DIR_S) -name *.c)

OBJS	:= $(SRCS:%.c=$(DIR_O)/%.o)

SUB_DIR_O := $(shell find $(DIR_S) -type d)
SUB_DIR_O := $(SUB_DIR_O:%=$(DIR_O)/%)
# OBJS := $(SRCS:%=$(DIR_O)/%.o)

BSRCS	:=	$(SRCS) \

# TSRCS	:=	$(SRCS) main.c

# TOBJS	:=	$(TSRCS:.c=.o)

# BOBJS	=	$(BSRCS:.c=.o)

DEPS	=	$(HEADERS)/ft_cub3d.h

BDEPS	:=	$(DEPS)

CC		=	gcc

# Change optimization flag to -O3 for faster execution
CFLAGS	=	-O0 -Wall -Wextra

# Linux Libs
LIBS	=	-lm -L./libft -lft -lmlx -lX11 -lbsd -lXext

# Mac Libs
LIBS	=	-lm -L./libft -lft -lmlx -framework OpenGL -framework AppKit

RM		=	rm -f

INCLUDES	= -I/libft/ -I/headers/

# After that, to compile your project:
# clang -Wall -Wextra -Werror main.c -lbsd -lmlx -lXext -lX11

$(DIR_O)/%.o: %.c
			@mkdir -p $(DIR_O)
			@mkdir -p $(SUB_DIR_O)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME):	$(DEPS) $(OBJS)
			# @make all -C $(MINILIBX)
			@make bonus -C $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

all:		$(NAME)

# test:		$(DEPS) $(TOBJS)
# 			@make bonus -C $(LIBFT)
# 			@cp libft/libft.a ./$(NAME)
# 			$(CC) -g -fsanitize=address $(NAME) $(TOBJS) -o test

cubclean:
			$(RM) $(OBJS)
			$(RM) $(BOBJS)

clean:		cubclean
			@make clean -C $(LIBFT)
			@make clean -C $(MINILIBX)

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C $(LIBFT)

re:			fclean all
			@make fclean -C $(LIBFT)

# bonus:		$(BDEPS) $(BOBJS)
# 			@make bonus -C $(LIBFT)
# 			@cp libft/libft.a ./$(NAME)
# 			ar rc $(NAME) $(BOBJS)

.PHONY:		all clean fclean re bonus
