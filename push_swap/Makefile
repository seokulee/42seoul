CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= libft.a
PRINTF		= ft_printf
PRINTF_LIB	= libftprintf.a
PS_LIB		= push_swap.a
AR			= ar
ARFLAGS 	= crs
ARC			= $(LIBFT_LIB) $(PRINTF_LIB) $(PS_LIB)
SRC			= push_swap \
			data_preprocessing \
			node_new \
			node_del \
			lst_new \
			lst_clear \
			lst_add_head \
			lst_add_tail \
			lst_del_head \
			lst_del_tail \
			lst_print \
			lst_print \
			push \
			swap \
			rotate \
			reverse_rotate \
			check_dup \
			quicksort
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

$(NAME):	$(ARC)
	$(CC) -o $@ $^

$(PS_LIB):	$(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

$(LIBFT_LIB):
	make all -C $(PRINTF)/$(LIBFT)/
	cp $(PRINTF)/$(LIBFT)/$@ ./

$(PRINTF_LIB):
	make all -C $(PRINTF)/
	cp $(PRINTF)/$@ ./

bonus:
	@make WITH_BONUS=1 all

all:		$(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BNS)
	make clean -C $(PRINTF)
	make clean -C $(PRINTF)/$(LIBFT)

fclean:		clean
	rm -f $(NAME)
	rm -f $(ARC)
	make fclean -C $(PRINTF)
	make fclean -C $(PRINTF)/$(LIBFT)

re:			fclean all

.PHONY: all clean fclean re bonus