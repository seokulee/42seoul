# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 15:10:24 by seokklee          #+#    #+#              #
#    Updated: 2023/07/11 15:10:25 by seokklee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar
RM		= rm
RMFLAGS	= -rf
INCS	= -I $(FDF_HDR_DIR) -I $(LIBFT_HDR) -I $(MLX_HDR)

NAME	= fdf

# OTHER LIBRARY
LIBFT	= $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HDR = $(LIBFT_DIR)include/

MLX		= libmlx.dylib
MLX_DIR	= ./minilibx/
MLX_HDR	= $(MLX_DIR)

# HEADERS
FDF_HDRS	= fdf.h
FDF_HDR_DIR	= ./include/
FDF_HDR		= $(addprefix $(FDF_HDR_DIR), $(FDF_HDRS))

# src
SRC		= main.c \
		change_key.c \
		change_mouse.c \
		color.c \
		draw.c \
		functions.c \
		get_next_line.c \
		init.c \
		io_cntl.c \
		read_map.c \
		rotate.c \
		transform.c \

SRC_DIR	= ./src/
SRCS	= $(addprefix $(SRC_DIR), $(SRC))

# obj
OBJ		= $(SRC:.c=.o)
OBJ_DIR	= obj/
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(INCS) $(OBJS) -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(FDF_HDR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)
	mv $(MLX_DIR)$(MLX) ./

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean
	$(RM) $(RMFLAGS) $(MLX)
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re