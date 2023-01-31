# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 16:13:05 by jvigny            #+#    #+#              #
#    Updated: 2022/11/14 11:36:12 by jvigny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJ =	${SRCS:.c=.o}
OBJ_BONUS = ${BONUS:.c=.o}
NAME =	libft.a
FLAGS =	-Wall -Werror -Wextra -I.
CC =	cc

all:	${NAME}

${NAME}:	${OBJ}
	ar rcs ${NAME} ${OBJ}

bonus:	${OBJ_BONUS} ${OBJ}
	ar rcs ${NAME} ${OBJ_BONUS} ${OBJ}

%.o:	%.c
	${CC} ${FLAGS} -c -o $@ $<

clean:
	rm -f ${OBJ} ${OBJ_BONUS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all re clean fclean 
