# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 11:22:34 by seokklee          #+#    #+#              #
#    Updated: 2023/08/07 12:18:22 by seokklee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar
RM		= rm
RMFLAGS	= -rf
INCS	= -I $(HDR_DIR)
NAME	= philo

# HEADERS
HDRS	= philo_bonus.h
HDR_DIR	= ./include/
HDR		= $(addprefix $(HDR_DIR), $(HDRS))

# src
SRC		= main_bonus.c \
		init_bonus.c \
		utils_bonus.c \
		ft_atoi_bonus.c \
		routine_bonus.c


SRC_DIR	= ./src/
SRCS	= $(addprefix $(SRC_DIR), $(SRC))

# obj
OBJ		= $(SRC:.c=.o)
OBJ_DIR	= obj/
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(HDR)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean:	clean
	$(RM) $(RMFLAGS) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
