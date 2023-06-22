# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 13:00:03 by jmarinho          #+#    #+#              #
#    Updated: 2023/05/30 12:10:41 by jmarinho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isalnum.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_atoi.c ft_calloc.c ft_memchr.c ft_memcmp.c \
	ft_strchr.c ft_strdup.c ft_strlcat.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c \
	ft_putchar_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c \
	ft_printf.c ft_print_char.c ft_print_hexa.c ft_print_pointer.c \
	ft_print_int.c ft_print_unint.c ft_print_string.c ft_print_percent.c \
	get_next_line_bonus.c get_next_line_utils_bonus.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
	ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \

NAME = libft.a

OBJS = ${SRC:.c=.o}

RM = rm -f

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

$(NAME): ${OBJS}
	@ar rcs ${NAME} ${OBJS}
.c.o:
	@cc ${FLAGS} -c $< -o ${<:.c=.o}

clean:
	@${RM} ${OBJS}

fclean: clean 
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.SILENT:
