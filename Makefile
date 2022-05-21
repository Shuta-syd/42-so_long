# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 15:04:02 by shogura           #+#    #+#              #
#    Updated: 2022/05/21 17:28:02 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -g #-Wall -Wextra -Werror

MLX = mlx/libmlx_Darwin.a

LIBFT = src/libft/libft.a

SRC_FILES = so_long.c scan_map.c init_window.c init_image.c output_map.c\
						hook_action.c

SRC_GNL = gnl/get_next_line.c

SRC = ${addprefix src/, ${SRC_FILES} ${SRC_GNL}}

OBJS = ${SRC:.c=.o}

ifdef home
	MFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
else
	MFLAG = -lmlx -framework OpenGL -framework AppKit
endif

all: ${NAME}

${NAME}:${OBJS} ${MLX} ${LIBFT}
	${CC} ${CFLAGS} ${MFLAG} -o $@ $^
	@make clean

${LIBFT}:
	@make -C src/libft

${MLX}:
	@make -C ./mlx

home:
	@make home=1 all

clean:
	${RM} ${OBJS}
	make clean -C ./mlx
	make clean -C ./src/libft

fclean:clean
	${RM} ${NAME}

re: fclean all
