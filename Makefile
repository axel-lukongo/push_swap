# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 17:14:48 by alukongo          #+#    #+#              #
#    Updated: 2022/04/08 16:26:21 by alukongo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

RM = rm -rf

NAME = push_swap

MANDATORY = parsing.c\
			main.c\
			utils.c\
			init_list.c\

MANDATORY_SRCS	=	${MANDATORY}

BONUS_SRCS	=	${BONUS}

MANDATORY_OBJS	= ${MANDATORY_SRCS:.c=.o}

CFLAGS	= -g -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${MANDATORY_OBJS}
		make -C libft
		make -C ft_printf
		${CC} ${CFLAGS} ${MANDATORY_SRCS} libft/libft.a ft_printf/libftprintf.a -o ${NAME}

all: ${NAME}

clean:
	${RM} ${MANDATORY_OBJS}

fclean: clean
	make fclean -C ft_printf
	make fclean -C libft
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re