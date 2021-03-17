# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 14:13:08 by msessa            #+#    #+#              #
#    Updated: 2021/03/17 17:12:17 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

LIBFT	=	libft

HEADERS	=	includes

SOURCES	=	ft_printf.c \
			ft_arg_param.c \
			ft_arg_utils.c \
			ft_flag_utils.c \
			ft_free.c \
			ft_list_str_part.c \
			ft_get_args.c \
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

DIR_S	=	srcs

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

DIR_O	=	obj

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

BSRCS	:=	$(SRCS) \

TSRCS	:=	$(SRCS) main.c

TOBJS	:=	$(TSRCS:.c=.o)

BOBJS	=	$(BSRCS:.c=.o)

DEPS	=	$(HEADERS)/ft_printf.h \
			$(HEADERS)/ft_my_types.h \
			$(HEADERS)/ft_number_printers.h \
			$(HEADERS)/ft_printer.h \

BDEPS	:=	$(DEPS)

CC		=	gcc

CFLAGS	=	-g -Wall -Wextra -Werror

RM		=	rm -f

$(DIR_O)/%.o: $(DIR_S)/%.c $(DEPS)
			@mkdir -p obj
			@mkdir -p obj/printer
			@mkdir -p obj/number_printers
			@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(DEPS) $(OBJS)
			@make bonus -C $(LIBFT)
			@cp libft/libft.a ./$(NAME)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

test:		$(DEPS) $(TOBJS)
			@make bonus -C $(LIBFT)
			@cp libft/libft.a ./$(NAME)
			$(CC) -g -fsanitize=address $(NAME) $(TOBJS) -o test

clean:
			$(RM) $(OBJS)
			$(RM) $(BOBJS)
			@make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C $(LIBFT)

re:			fclean all
			@make fclean -C $(LIBFT)

bonus:		$(BDEPS) $(BOBJS)
			ar rc $(NAME) $(BOBJS)
			@make bonus -C $(LIBFT)

.PHONY:		all clean fclean re bonus