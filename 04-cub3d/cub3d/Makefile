# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msessa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 11:32:44 by msessa            #+#    #+#              #
#    Updated: 2021/05/14 15:40:20 by msessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

LIBFT	=	libft

HEADERS	=	headers

DIR_S	=	srcs

DIR_O	=	obj

O_SRCS	:=	srcs/events/ft_process_item.c \
			srcs/events/ft_set_events.c \
			srcs/events/ft_ply_movements.c \
			srcs/init_game/ft_game_memory.c \
			srcs/init_game/ft_init_game.c \
			srcs/init_game/ft_init_game_utility.c \
			srcs/main.c \
			srcs/map/ft_map_utility.c \
			srcs/map/ft_map_size.c \
			srcs/map/ft_get_next_line.c \
			srcs/map/ft_map_memory.c \
			srcs/map/ft_save_file.c \
			srcs/map/ft_map_param.c \
			srcs/map/ft_map_grid_utility.c \
			srcs/map/ft_init_map.c \
			srcs/map/ft_check_map_grid.c \
			srcs/map/ft_map_grid.c \
			srcs/mini-map/ft_mini_map.c \
			srcs/mini-map/ft_mm_print_utility.c \
			srcs/mini-map/ft_mm_print.c \
			srcs/ray_caster/ft_rays_set.c \
			srcs/ray_caster/ft_rays_init.c \
			srcs/ray_caster/ft_ray_set_y.c \
			srcs/ray_caster/ft_ray_utility.c \
			srcs/ray_caster/ft_ray_set_x.c \
			srcs/run_game/ft_lifebar.c \
			srcs/run_game/ft_scene.c \
			srcs/run_game/ft_print_utility.c \
			srcs/run_game/ft_run_game.c \
			srcs/save_bmp/ft_save_bmp.c \
			srcs/save_bmp/ft_bmp_headers.c \
			srcs/textures/ft_sprites_utility.c \
			srcs/textures/ft_init_tex.c \
			srcs/textures/ft_set_sprites.c \
			srcs/textures/ft_init_sprites.c \
			srcs/textures/ft_draw_sprites.c \
			srcs/textures/ft_textures.c \
			srcs/utilities/ft_mem_utilities.c \
			srcs/utilities/ft_errors.c 

SRCS	:=	$(O_SRCS) \
			srcs/run_game/ft_update_time.c

B_SRCS	:=	$(O_SRCS) \
			srcs/run_game/ft_update_time_bonus.c

OBJS	:= $(SRCS:%.c=$(DIR_O)/%.o)

BOBJS	:= $(B_SRCS:%.c=$(DIR_O)/%.o)

SUB_DIR_O := $(shell find $(DIR_S) -type d)
SUB_DIR_O := $(SUB_DIR_O:%=$(DIR_O)/%)

DEPS	=	$(HEADERS)/ft_init_map.h \
			$(HEADERS)/ft_ray_caster.h \
			$(HEADERS)/ft_mini_map.h \
			$(HEADERS)/ft_run_game.h \
			$(HEADERS)/ft_save_bmp.h \
			$(HEADERS)/ft_set_events.h \
			$(HEADERS)/ft_types.h \
			$(HEADERS)/ft_bonus.h \
			$(HEADERS)/ft_tests.h \
			$(HEADERS)/ft_cub3d.h \
			$(HEADERS)/ft_textures.h \
			$(HEADERS)/ft_constants.h \
			$(HEADERS)/ft_init_game.h \
			$(HEADERS)/ft_errors.h \
			$(HEADERS)/ft_utilities.h

CC		=	gcc

# Change optimization flag to -O3 for faster execution
CFLAGS	=	-O3 -Wall -Wextra -Werror

# Linux Libs
# LIBS	=	-lm -L./libft -lft -lmlx -lX11 -lbsd -lXext

# Mac Libs
LIBS	=	-lm -L./libft -lft -lmlx -framework OpenGL -framework AppKit

RM		=	rm -f

INCLUDES	= -I/libft/ -I/headers/

$(DIR_O)/%.o: %.c
			@mkdir -p $(DIR_O)
			@mkdir -p $(SUB_DIR_O)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME):	$(DEPS) $(OBJS)
			@make bonus -C $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

all:		$(NAME)

cubclean:
			$(RM) $(OBJS)
			$(RM) $(BOBJS)

clean:		cubclean
			@make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C $(LIBFT)

re:			fclean all

bonus:		$(DEPS) $(BOBJS)
			@make bonus -C $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(BOBJS) $(LIBS)

.PHONY:		all clean fclean cubclean re bonus
