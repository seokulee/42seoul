CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= pipex
AR			= ar
ARFLAGS 	= crs
SRC_PATH	= src/
SRC_B_PATH	= src_bonus/
OBJ_PATH	= obj/
OBJ_B_PATH	= obj_bonus/
SRC			= main.c \
			init_pack.c \
			get_cmd.c \
			get_path.c \
			functions.c \
			errors.c \
			exe_cmd.c \
			ft_split.c \
			str_utils.c 
SRC_BONUS	= main_bonus.c \
			init_pack_bonus.c \
			get_cmd_bonus.c \
			get_path_bonus.c \
			functions_bonus.c \
			errors_bonus.c \
			exe_cmd_bonus.c \
			ft_split_bonus.c \
			str_utils_bonus.c 
OBJ			= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
SRCS_BONUS	= $(addprefix $(SRC_B_PATH), $(SRC_BONUS))
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
OBJS_BONUS	= $(addprefix $(OBJ_B_PATH), $(OBJ_BONUS))
INCS		= ./include/

ifdef WITH_BONUS
    OBJF = $(OBJS_BONUS)
else
    OBJF = $(OBJS)
endif

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJF)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(OBJ_B_PATH) $(OBJS_BONUS)
	@make WITH_BONUS=1 all

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