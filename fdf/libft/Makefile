# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 15:45:22 by seokklee          #+#    #+#              #
#    Updated: 2023/07/03 14:33:33 by seokklee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libft.a
AR			= ar
ARFLAGS 	= crs
SRC_PATH	= ./src
SRC_B_PATH	= ./src_bonus
OBJ_PATH	= obj/
OBJ_B_PATH	= obj_bonus/
INCS		= ./include/
SRC			= ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c
SRC_BNS 	= ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJ			= $(SRC:.c=.o)
OBJ_BNS	= $(SRC_BNS:.c=.o)
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
SRCS_BNS	= $(addprefix $(SRC_B_PATH), $(SRC_BNS))
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
OBJS_BNS	= $(addprefix $(OBJ_B_PATH), $(OBJ_BNS))
INCS		= ./include/

ifdef		WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_BNS)
else
	OBJECTS = $(OBJS)
endif

all: $(OBJ_PATH) $(NAME)

$(NAME):	$(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_PATH)%.o :		$(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCS)

$(OBJ_B_PATH)%.o :	$(SRC_B_PATH)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCS)

bonus: $(OBJ_B_PATH) $(OBJS_BNS)
	@make WITH_BONUS=1 all

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_B_PATH):
	mkdir $(OBJ_B_PATH)
clean:
	rm -rf $(OBJ_PATH) $(OBJ_B_PATH)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus
