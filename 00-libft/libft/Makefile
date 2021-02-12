# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 14:13:08 by msessa            #+#    #+#              #
#    Updated: 2021/01/18 16:24:31 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

BSRCS	:=	$(SRCS) \
			bonus_ft_lstnew.c bonus_ft_lstadd_front.c \
			bonus_ft_lstsize.c \
			bonus_ft_lstlast.c \
			bonus_ft_lstadd_back.c \
			bonus_ft_lstdelone.c \
			bonus_ft_lstclear.c \
			bonus_ft_lstiter.c \
			bonus_ft_lstmap.c \

OBJS	=	$(SRCS:.c=.o)

BOBJS	=	$(BSRCS:.c=.o)

NAME	=	libft.a

DEPS	=	libft.h

BDEPS	:=	$(DEPS) bonus_libft.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

$(NAME):	$(DEPS) $(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		$(BDEPS) $(BOBJS)
			ar rc $(NAME) $(BOBJS)

so:
			$(CC) -c $(CFLAGS) -fPIC $(BSRCS)
			gcc -shared -o libft.so $(BOBJS)

.PHONY:		all clean fclean re bonus