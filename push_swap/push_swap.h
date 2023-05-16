#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include "./ft_printf/ft_printf.h"

typedef struct	s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
}	t_node;

typedef struct	s_list
{
	t_node	*head;
	t_node	*tail;
	int		count;
}	t_list;

void	lst_add_head(t_list *lst, t_node *new_node);
void	lst_add_tail(t_list *lst, t_node *new_node);
void	lst_clear(t_list *lst);
void	lst_del_head(t_list *lst);
void	lst_del_tail(t_list *lst);
t_list	*lst_new(void);
void	lst_print(t_list *lst);
t_node	*node_new(int value);
void	node_del(t_node *target);
void	push(t_list *donor, t_list *recipient);
void	swap(t_list *lst);
void	rotate(t_list *lst);
void	reverse_rotate(t_list *lst);
int		data_preprocessing(int argc, char **argv, t_list *a);
int		check_dup(t_list *lst, int input);
void	quicksort(t_list *lst, t_node *head, t_node *tail);

#endif