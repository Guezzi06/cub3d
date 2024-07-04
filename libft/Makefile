# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 12:56:34 by aguezzi           #+#    #+#              #
#    Updated: 2023/06/05 00:15:44 by aguezzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_len.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_printf_hex_maj.c ft_printf_hex_min.c ft_printf_hex_ptr.c ft_printf_nbr.c ft_printf_perc.c ft_printf_ptr.c \
ft_printf_uns_int.c ft_putchar.c ft_putstr.c ft_strcmp.c get_next_line.c ft_strjoin_gnl.c

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

OBJS	= ${SRCS:.c=.o}

BONUS_OBJS	= ${BONUS:.c=.o}

RM	= rm -f

all:	${NAME}

.c.o:
		@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		@ar -rc ${NAME} ${OBJS}

bonus:		${OBJS} ${BONUS_OBJS}
		@ar -rc ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
		@${RM} ${OBJS} ${BONUS_OBJS}

fclean:	clean
		@${RM} ${NAME} ${BONUS_OBJS}

re:	fclean all

.PHONY:	all clean fclean re

