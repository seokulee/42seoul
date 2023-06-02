CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= pipex
PIPE_LIB	= pipex.a
AR			= ar
ARFLAGS 	= crs
SRC_PATH	= src/
SRC_B_PATH	= src_bonus/
OBJ_PATH	= obj/
OBJ_B_PATH	= obj_bonus/
SRC			= main.c \
			
SRC_BONUS	= 
OBJ			= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
SRCS_BONUS	= $(addprefix $(SRC_B_PATH), $(SRC_BONUS))
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
OBJS_BONUS	= $(addprefix $(OBJ_B_PATH), $(OBJ_BONUS))
INCS		= ./include/

all: $(OBJ_PATH) $(NAME)

$(NAME): $(PIPE_LIB)
	$(CC) $^ -o $@

bonus: $(OBJ_B_PATH)

$(PIPE_LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCS)

$(OBJ_B_PATH)%.o: $(SRC_B_PATH)%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_B_PATH):
	mkdir $(OBJ_B_PATH)

clean:
	rm -rf $(OBJ_PATH) $(OBJ_B_PATH) $(PIPE_LIB)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re