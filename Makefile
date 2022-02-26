# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 14:47:54 by mcerchi           #+#    #+#              #
#    Updated: 2022/02/26 14:49:31 by mcerchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_BONUS	=	checker

SRC			=	push_swap.c utils.c operations_one.c operations_two.c\
				operations_three.c order.c order_two.c order_three.c\
				lis.c sort.c\

SRC_BONUS	=	checker.c check_write.c check_op_one.c check_op_two.c\
				check_op_three.c\

LIBFT		=	libft/libft.a

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C libft
			${RM} $(OBJ) $(OBJ_BONUS)

fclean: 	clean
			make fclean -C libft
			${RM} $(NAME) $(NAME_BONUS) ${OBJ} $(OBJ_BONUS)

re:			fclean bonus

bonus:		all $(OBJ_BONUS)
			$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)


.PHONY:		all clean fclean re
