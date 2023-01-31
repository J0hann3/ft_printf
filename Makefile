# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 14:02:30 by jvigny            #+#    #+#              #
#    Updated: 2022/11/17 10:38:01 by jvigny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c list.c convertion.c convertion2.c

OBJ =	${SRCS:.c=.o}
NAME =	libftprintf.a
FLAGS =	-Wall -Werror -Wextra -I.
CC =	gcc

all:	${NAME}

${NAME}:	${OBJ}
	make -C libft
	ar rcs ${NAME} ${OBJ} libft/*.o

%.o:	%.c
	${CC} ${FLAGS} -c -o $@ $<

clean:
	make clean -C libft
	rm -f ${OBJ}

fclean:	clean
	make fclean -C libft
	rm -f ${NAME}

re:	fclean all

.PHONY:	all re clean fclean 
