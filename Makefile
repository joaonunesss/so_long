# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 15:22:11 by jmarinho          #+#    #+#              #
#    Updated: 2023/06/21 16:01:56 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#    Created: 2023/05/12 08:04:49 by wcorrea-          #+#    #+#              #
#    Updated: 2023/05/15 22:31:58 by wcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c create_map.c render.c utils.c check_map.c \
		clean_and_exit.c\

NAME = so_long.a

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
		cc ${OBJS} ${LIBFT} ${MLX} -o so_long

clean:
		${MAKE} ${LIBFT_PATH} clean
		${MAKE} ${MLX_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} so_long

re: fclean all

.PHONY: all clean fclean re

.SILENT:
