# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 15:56:12 by seokklee          #+#    #+#              #
#    Updated: 2023/05/25 14:57:23 by seokklee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= push_swap
PS_LIB		= push_swap.a
CHECKER		= checker
CHECKER_LIB	= checker.a
AR			= ar
ARFLAGS 	= crs
SRC_PATH	= src/
SRC_B_PATH	= src_bonus/
OBJ_PATH	= obj/
OBJ_B_PATH	= obj_bonus/
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
			rrr_controler.c \
			quick_sort.c
SRC_BONUS	= main.c \
			checker_bonus.c \
			get_data_bonus.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c \
			list_add_head_bonus.c \
			list_add_tail_bonus.c \
			list_clear_bonus.c \
			list_del_bonus.c \
			list_new_bonus.c \
			node_clear_bonus.c \
			node_new_bonus.c \
			ps_atoi_bonus.c \
			str_split_bonus.c \
			str_utils_bonus.c \
			push_bonus.c \
			swap_bonus.c \
			rotate_bonus.c \
			reverse_rotate_bonus.c \
			is_sorted_bonus.c 
OBJ			= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
SRCS_BONUS	= $(addprefix $(SRC_B_PATH), $(SRC_BONUS))
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
OBJS_BONUS	= $(addprefix $(OBJ_B_PATH), $(OBJ_BONUS))
INCS		= ./include/

all: $(OBJ_PATH) $(NAME)

$(NAME): $(PS_LIB)
	$(CC) $^ -o $@

bonus: $(OBJ_B_PATH) $(CHECKER)

$(CHECKER): $(CHECKER_LIB)
	$(CC) $^ -o $@

$(PS_LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(CHECKER_LIB): $(OBJS_BONUS)
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
	rm -rf $(OBJ_PATH) $(OBJ_B_PATH) $(PS_LIB) $(CHECKER_LIB)

fclean:		clean
	rm -f $(NAME) $(CHECKER)

re:			fclean all

.PHONY: all clean fclean re