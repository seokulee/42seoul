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
			functions.c \
			errors.c \
			child.c \
			get_cmd.c \
			get_path.c \
			ft_str_utils.c \
			ft_split.c \
			sub_quotation.c 
SRC_BONUS	= main.c \
			functions.c \
			errors.c \
			child.c \
			get_cmd.c \
			get_path.c \
			ft_str_utils.c \
			ft_split.c \
			sub_quotation.c 
OBJ			= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
SRCS_BONUS	= $(addprefix $(SRC_B_PATH), $(SRC_BONUS))
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
OBJS_BONUS	= $(addprefix $(OBJ_B_PATH), $(OBJ_BONUS))
INCS		= ./include/
all: $(OBJ_PATH) $(NAME)

