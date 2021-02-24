# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 14:13:08 by msessa            #+#    #+#              #
#    Updated: 2021/02/24 19:54:05 by msessa           ###   ########.fr        #
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
			itoa/ft_ullitoa.c \
			itoa/ft_usitoa.c \
			libft/ft_memset.c \
			libft/ft_bzero.c \
			libft/ft_memcpy.c \
			libft/ft_memccpy.c \
			libft/ft_memmove.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_strlen.c \
			libft/ft_strlcpy.c \
			libft/ft_strlcat.c \
			libft/ft_strchr.c \
			libft/ft_strrchr.c \
			libft/ft_strnstr.c \
			libft/ft_strncmp.c \
			libft/ft_atoi.c \
			libft/ft_isalpha.c \
			libft/ft_isdigit.c \
			libft/ft_isalnum.c \
			libft/ft_isascii.c \
			libft/ft_isprint.c \
			libft/ft_toupper.c \
			libft/ft_tolower.c \
			libft/ft_calloc.c \
			libft/ft_strdup.c \
			libft/ft_substr.c \
			libft/ft_strjoin.c \
			libft/ft_strtrim.c \
			libft/ft_split.c \
			libft/ft_itoa.c \
			libft/ft_strmapi.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_lstnew.c \
			libft/ft_lstadd_front.c \
			libft/ft_lstsize.c \
			libft/ft_lstlast.c \
			libft/ft_lstadd_back.c \
			libft/ft_lstdelone.c \
			libft/ft_lstclear.c \
			libft/ft_lstiter.c \
			libft/ft_lstmap.c \

BSRCS	:=	$(SRCS) \

OBJS	=	$(SRCS:.c=.o)

BOBJS	=	$(BSRCS:.c=.o)

NAME	=	libftprintf.a

DEPS	=	ft_printf.h \
			ft_my_types.h \
			itoa/ft_itoa.h \
			printer/ft_printer.h \
			libft/libft.h \

BDEPS	:=	$(DEPS)

CC		=	gcc

CFLAGS	=	-g -Wall -Wextra #-Werror

RM		=	rm -f

$(NAME):	$(DEPS) $(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

test:		$(DEPS) $(OBJS)
			$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o test

clean:
			$(RM) $(OBJS)
			$(RM) $(BOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		$(BDEPS) $(BOBJS)
			ar rc $(NAME) $(BOBJS)

.PHONY:		all clean fclean re bonus