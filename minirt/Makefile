CC		= cc
CFLAGS	= #-Wall -Werror -Wextra
AR		= ar
RM		= rm
RMFLAGS	= -rf
INCS	= -I $(MINIRT_HDR_DIR) -I $(LIBFT_HDR) -I $(MLX_HDR)

NAME	= miniRT

# OTHER LIBRARY
LIBFT	= $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HDR = $(LIBFT_DIR)include/

MLX		= libmlx.dylib
MLX_DIR	= ./minilibx/
MLX_HDR	= $(MLX_DIR)

# HEADERS
MINIRT_HDRS	= minirt.h \
			get_next_line.h
MINIRT_HDR_DIR	= ./include/
MINIRT_HDR		= $(addprefix $(MINIRT_HDR_DIR), $(MINIRT_HDRS))

# src
SRC				= main.c

SRCS_PARSING	= init.c \
				read_file.c \
				get_by_id.c \
				get_functions.c \

SRCS_DRAW		= draw.c

SRCS_EVENT		= event_handler.c

SRCS_UTILS		= get_next_line.c \
				get_next_line_utils.c \
				free.c \
				error.c \
				ft_my.c

SRC_DIR	= src/
SRC_PARSING_DIR	= $(SRC_DIR)parsing/
SRC_DRAW_DIR	= $(SRC_DIR)draw/
SRC_EVENT_DIR	= $(SRC_DIR)event/
SRC_UTILS_DIR	= $(SRC_DIR)utils/

SRCS	= $(addprefix $(SRC_DIR), $(SRC)) \
		$(addprefix $(SRC_PARSING_DIR), $(SRCS_PARSING)) \
		$(addprefix $(SRC_DRAW_DIR), $(SRCS_DRAW)) \
		$(addprefix $(SRC_EVENT_DIR), $(SRCS_EVENT)) \
		$(addprefix $(SRC_UTILS_DIR), $(SRCS_UTILS))

# obj
OBJ		= $(SRCS:.c=.o)
OBJS_DIR	= obj/
OBJS	= $(addprefix $(OBJS_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(INCS) $(OBJS) -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)
	mkdir $(OBJS_DIR)$(SRC_DIR)
	mkdir $(OBJS_DIR)$(SRC_PARSING_DIR)
	mkdir $(OBJS_DIR)$(SRC_DRAW_DIR)
	mkdir $(OBJS_DIR)$(SRC_EVENT_DIR)
	mkdir $(OBJS_DIR)$(SRC_UTILS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(MINIRT_HDR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)
	mv $(MLX_DIR)$(MLX) .

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean:
	make clean
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean
	$(RM) $(RMFLAGS) $(MLX)
	$(RM) $(RMFLAGS) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
