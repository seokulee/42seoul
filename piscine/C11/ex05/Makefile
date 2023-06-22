CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
SRC = srcs
INC = ./includes/
NAME = do-op
SRCS = $(SRC)/main.c $(SRC)/ft_putnbr.c $(SRC)/ft_putstr.c $(SRC)/ft_putchar.c $(SRC)/ft_printerr.c $(SRC)/ft_do_op.c $(SRC)/ft_is.c $(SRC)/ft_atoi.c $(SRC)/ft_cal.c $(SRC)/ft_strlen.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ -I $(INC)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
