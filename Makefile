# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 15:22:11 by jmarinho          #+#    #+#              #
#    Updated: 2023/06/23 13:24:26 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c create_sl_map.c libx.c utils.c check_errors.c \
		clean_and_exit.c moves.c \

NAME = so_long

OBJS = ${SRC:.c=.o}

RM = rm -f

FLAGS = -Wall -Wextra -Werror

MAKE = make -C

LIBFT_PATH = lib/libft

MLX_PATH = lib/mlx

LIBFT = -L ${LIBFT_PATH} -lft

MLX	= -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm 

all: ${NAME}

$(NAME): ${OBJS}
		${MAKE} ${LIBFT_PATH}
		${MAKE} ${MLX_PATH}
		cc ${FLAGS} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${MAKE} ${MLX_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.SILENT:
