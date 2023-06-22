CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = srcs
INC = includes
NAME = libft.a
SRCS = $(SRC)/ft_putchar.c $(SRC)/ft_swap.c $(SRC)/ft_putstr.c $(SRC)/ft_strlen.c $(SRC)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
