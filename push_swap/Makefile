CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= push_swap.a
AR			= ar
ARFLAGS 	= crs
SRC			= push_swap \
			node_new \
			node_del \
			lst_new \
			lst_add_head \
			lst_add_tail \
			lst_del_head \
			lst_del_tail \
			lst_print \
			lst_print \
			push \
			swap \
			rotate \
			reverse_rotate
SRC_BNS 	= 
SRCS		= $(addprefix ./, $(addsuffix .c, $(SRC)))
SRCS_BNS	= $(addprefix ./, $(addsuffix .c, $(SRC_BNS)))
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