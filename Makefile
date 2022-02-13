# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 16:37:50 by fdrudi            #+#    #+#              #
#    Updated: 2022/02/13 18:28:15 by fdrudi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c utils.c operations_one.c operations_two.c operations_three.c\

HDRS = ./libft/libft.h

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o: %.c
	gcc -Wall -Wextra -Werror -I ${HDRS} -c $< -o $@

$(NAME): $(OBJ)
	make -C ./libft/
	gcc $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	${RM} $(OBJ)

fclean: clean
	${RM} $(NAME) ${OBJ}

re: $(NAME)

.PHONY: all clean fclean re
