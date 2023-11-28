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
MINIRT_HDRS	= math_vec.h\
		print.h\
		scene.h\
		structure.h\
		trace.h\
		error.h
MINIRT_HDR_DIR	= ./include/
MINIRT_HDR		= $(addprefix $(MINIRT_HDR_DIR), $(MINIRT_HDRS))

# src
SRC				= main.c

SRCS_PRINT		= print.c

SRCS_SCENE		= canvas.c \
				scene.c \
				object_create.c

SRCS_TRACE		= ray.c \
				phong_lightning.c

SRCS_HIT		= hit_sphere.c \
				normal.c \
				hit.c
#				hit_plane.c \
				hit_square.c \
				hit_cylinder.c \
				hit_triangle.c

SRCS_UTILS		= math_vec.c \
				obj_list.c

SRCS_ERROR		= error.c\

SRC_DIR	= src/
SRC_PRINT_DIR = src/print/
SRC_SCENE_DIR = src/scene/
SRC_TRACE_DIR = src/trace/
SRC_HIT_DIR = src/trace/hit/
SRC_UTILS_DIR = src/utils/
SRC_ERROR_DIR = src/error/

SRCS	= $(addprefix $(SRC_DIR), $(SRC)) \
		$(addprefix $(SRC_PRINT_DIR), $(SRCS_PRINT)) \
		$(addprefix $(SRC_SCENE_DIR), $(SRCS_SCENE)) \
		$(addprefix $(SRC_TRACE_DIR), $(SRCS_TRACE)) \
		$(addprefix $(SRC_HIT_DIR), $(SRCS_HIT)) \
		$(addprefix $(SRC_UTILS_DIR), $(SRCS_UTILS)) \
		$(addprefix $(SRC_ERROR_DIR), $(SRCS_ERROR)) \

# obj
OBJ		= $(SRCS:.c=.o)
OBJS_DIR	= obj/
OBJS	= $(addprefix $(OBJS_DIR), $(OBJ))

all: $(NAME)

# $(NAME): $(OBJS_DIR) $(OBJS)
$(NAME): $(LIBFT) $(MLX) $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(INCS) $(OBJS) -o $@

# $(CC) $(CFLAGS) $(INCS) $(OBJS) -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)
	mkdir $(OBJS_DIR)$(SRC_DIR)
	mkdir $(OBJS_DIR)$(SRC_PRINT_DIR)
	mkdir $(OBJS_DIR)$(SRC_SCENE_DIR)
	mkdir $(OBJS_DIR)$(SRC_TRACE_DIR)
	mkdir $(OBJS_DIR)$(SRC_HIT_DIR)
	mkdir $(OBJS_DIR)$(SRC_UTILS_DIR)
	mkdir $(OBJS_DIR)$(SRC_ERROR_DIR)


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
	$(RM) $(RMFLAGS) $(OBJS_DIR)

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
