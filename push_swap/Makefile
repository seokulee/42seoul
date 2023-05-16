CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= push_swap
AR			= ar
ARFLAGS 	= crs
SRC_PATH	= src/
OBJ_PATH	= obj/
SRC			=
OBJ			= $(SRC:.c=.o)
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
INCS		= ./include/

all: $(OBJ_PATH) $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re