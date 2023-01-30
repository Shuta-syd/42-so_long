# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 15:04:02 by shogura           #+#    #+#              #
#    Updated: 2022/06/05 15:23:43 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Imlx -g -Wall -Wextra -Werror

MLX = mlx/libmlx_Darwin.a

LIBFT = src/libft/libft.a

SRC_FILES = so_long.c scan_map.c init_window.c init_image.c output_map.c\
						hook_action.c error.c clear_game.c output_step.c move_monster.c

SRC_GNL = gnl/get_next_line.c

SRC = ${addprefix src/, ${SRC_FILES} ${SRC_GNL}}

OBJS = ${SRC:.c=.o}

NR = norminette -R CheckForbiddenSourceHeader

ifdef home
	MFLAG = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
else
	MFLAG = -lmlx -framework OpenGL -framework AppKit
endif

all: ${NAME}

${NAME}:
	cd mlx/ && ./configure
	${CC} ${CFLAGS} ${MFLAG} -o $@ ${SRC} ${MLX} ${LIBFT}

${LIBFT}:
	@make -C src/libft

home:
	@make home=1 all

nr:${SRC}
	${NR} $^ ./inc/so_long.h

clean:
	${RM} ${OBJS}
	make clean -C ./mlx
	make clean -C ./src/libft

fclean:clean
	${RM} ${NAME}

re: fclean all
