# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 13:10:43 by seokklee          #+#    #+#              #
#    Updated: 2023/03/26 17:35:49 by seokklee         ###   ########seoul.kr   #
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
#SRC_BNS 	=
SRCS		= $(addprefix ./ft_, $(addsuffix .c, $(SRC)))
#SRCS_BNS	= $(addprefix ./ft_, $(addsuffix .c, $(SRC_BNS)))
OBJS		= $(patsubst %.c, %.o, $(SRCS))
#OBJS_BNS	= $(patsubst %.c, %.o, $(SRCS_BNS))

ifdef		WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_BNS)
else
	OBJECTS = $(OBJS)
endif

%.o :		%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJECTS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $@
	$(AR) $(ARFLAGS) $@ $^

#bonus:
#	@make WITH_BONUS=1 all

all:		$(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BNS)
	make clean -C $(LIBFT)

fclean:		clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re:			fclean all

.PHONY: all clean fclean re bonus
