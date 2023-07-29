CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar
RM		= rm
RMFLAGS	= -rf
INCS	= -I $(HDR_DIR)

NAME	= philo

# HEADERS
HDRS	= philo.h
HDR_DIR	= ./include/
HDR		= $(addprefix $(HDR_DIR), $(HDRS))

# src
SRC		= main.c \
		init.c \
		utils.c \
		ft_atoi.c \
		thread.c \
		routine.c \

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

re: fclean all

.PHONY: all clean fclean re
