CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= push_swap
PS_LIB		= push_swap.a
AR			= ar
ARFLAGS 	= crs
SRC_PATH	= src/
OBJ_PATH	= obj/
SRC			= main.c \
			node_new.c \
			node_clear.c \
			list_new.c \
			list_clear.c \
			list_add_head.c \
			list_add_tail.c \
			list_del.c \
			get_data.c \
			ps_atoi.c \
			ps_itoa.c \
			str_split.c \
			str_utils.c \
			swap.c \
			push.c \
			rotate.c \
			reverse_rotate.c \
			sort.c \
			sort_a.c \
			sort_small_a.c \
			sort_b.c \
			sort_small_b.c \
			set_pivot.c \
			rrr_controler.c
OBJ			= $(SRC:.c=.o)
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
INCS		= ./include/

all: $(OBJ_PATH) $(NAME)

$(NAME): $(PS_LIB)
	$(CC) $^ -o $@

$(PS_LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH) $(PS_LIB)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re