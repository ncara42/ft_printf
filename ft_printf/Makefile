# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaravac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 08:08:58 by ncaravac          #+#    #+#              #
#    Updated: 2025/12/20 18:53:03 by ncaravac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
HD = ./includes
CFLAGS = -Wall -Werror -Wextra -fPIC -I${HD}

SRC = srcs/ft_printf.c\
	srcs/ft_putchar.c\
	srcs/ft_puthex.c\
	srcs/ft_putnbr.c\
	srcs/ft_putptr.c\
	srcs/ft_putstr.c\
	srcs/ft_putunsigned.c

OBJS_DIR = objs
OBJ = ${SRC:srcs/%.c=${OBJS_DIR}/%.o}

all: ${NAME}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}

${OBJS_DIR}/%.o: srcs/%.c Makefile includes/ft_printf.h
	@mkdir -p ${OBJS_DIR}
	@echo "Compiling: $<"
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -rf ${OBJS_DIR}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
