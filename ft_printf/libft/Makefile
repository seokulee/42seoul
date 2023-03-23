# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 15:45:22 by seokklee          #+#    #+#              #
#    Updated: 2023/03/20 20:32:56 by seokklee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libft.a
AR			= ar
ARFLAGS 	= crs
SRC			= isalpha \
			isdigit \
			isalnum \
			isascii \
			isprint \
			strlen \
			memset \
			bzero \
			memcpy \
			memmove \
			strlcpy \
			strlcat \
			toupper \
			tolower \
			strchr \
			strrchr \
			strncmp \
			memchr \
			memcmp \
			strnstr \
			atoi \
			calloc \
			strdup \
			substr \
			strjoin \
			strtrim \
			split \
			itoa \
			strmapi \
			striteri \
			putchar_fd \
			putstr_fd \
			putendl_fd \
			putnbr_fd
SRC_BNS 	= lstnew_bonus \
			lstadd_front_bonus \
			lstsize_bonus \
			lstlast_bonus \
			lstadd_back_bonus \
			lstdelone_bonus \
			lstclear_bonus \
			lstiter_bonus \
			lstmap_bonus
SRCS		= $(addprefix ./ft_, $(addsuffix .c, $(SRC)))
SRCS_BNS	= $(addprefix ./ft_, $(addsuffix .c, $(SRC_BNS)))
OBJS		= $(patsubst %.c, %.o, $(SRCS))
OBJS_BNS	= $(patsubst %.c, %.o, $(SRCS_BNS))

ifdef		WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_BNS)
else
	OBJECTS = $(OBJS)
endif

%.o :		%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

bonus:
	@make WITH_BONUS=1 all

all:		$(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BNS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus
