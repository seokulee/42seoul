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
LIBFT		= libft
LIBFT_LIB	= libft.a
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
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $@
	$(AR) $(ARFLAGS) $@ $^

all:		$(NAME)

clean:
	rm -f $(OBJS) 
	make clean -C $(LIBFT)

fclean:		clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re:			fclean all

.PHONY: all clean fclean re
