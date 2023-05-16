# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 13:10:43 by seokklee          #+#    #+#              #
#    Updated: 2023/03/31 11:42:27 by seokklee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a
AR			= ar
ARFLAGS 	= rcs
SRC			= printf \
			parsing \
			print_char \
			print_nbr \
			print_ptr \
			print_str \
			print_hex \
			print_u
SRCS		= $(addprefix ./ft_, $(addsuffix .c, $(SRC)))
OBJS		= $(patsubst %.c, %.o, $(SRCS))

%.o :		%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(AR) $(ARFLAGS) $@ $^

all:		$(NAME)

clean:
	rm -f $(OBJS) 

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
