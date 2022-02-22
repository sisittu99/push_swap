# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 16:37:50 by fdrudi            #+#    #+#              #
#    Updated: 2022/02/22 15:07:16 by fdrudi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC		=	push_swap.c utils.c operations_one.c operations_two.c operations_three.c\
			order.c order_two.c order_three.c\
			lis.c sort.c\

LIBFT	=	libft/libft.a

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

$(NAME):	$(OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C libft
			${RM} $(OBJ)

fclean: 	clean
			make fclean -C libft
			${RM} $(NAME) ${OBJ}

re:			fclean all

.PHONY:		all clean fclean re
