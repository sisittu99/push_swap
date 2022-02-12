NAME = pushe

SRC = push_swap.c

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
