CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= fdf
AR			= ar
ARFLAGS 	= crs
MLX_PATH	= ./minilibx_mms_20210621
MLX			= libmlx.dylib
SRC_PATH	= src/
SRC_B_PATH	= src_bonus/
OBJ_PATH	= obj/
OBJ_B_PATH	= obj_bonus/
SRC			= main.c \
			ft_atoi.c \
			ft_atoi_hex.c \
			ft_functions.c \
			ft_split.c \
			get_next_line.c \
			get_next_line_utils.c \
			init.c \
			init_map.c \
			init_mlx.c \
			measure_map.c \
			msg_error_no.c \
			parse_map.c \
			print_map.c \
			ft_string.c 
			
SRC_BONUS	= 

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
	make all -C $(MLX_PATH)/
	mv $(MLX_PATH)/$(MLX) ./
	$(CC) $(CFLAGS) $^ $(MLX) -o $@

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
	rm -rf $(MLX)
	make clean -C $(MLX_PATH)
fclean:		clean
	rm -f $(NAME)
re:			fclean all
.PHONY: all clean fclean re