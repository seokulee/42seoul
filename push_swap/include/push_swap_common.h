/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_common.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:07:57 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/25 15:08:08 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_COMMON_H
# define PUSH_SWAP_COMMON_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		count;
}	t_list;

t_node		*node_new(int value);
void		node_clear(t_node *target);
t_list		*list_new(void);
void		list_clear(t_list *lst);
void		list_add_head(t_list *lst, t_node *node);
void		list_add_tail(t_list *lst, t_node *node);
void		lst_del(t_list *lst);
int			get_data(int argc, char **argv, t_list *a);
char		**str_split(char const *s, char c);
long long	ps_atoi(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
void		do_sa(t_list *a);
void		do_sb(t_list *b);
void		do_ss(t_list *a, t_list *b);
void		do_pa(t_list *a, t_list *b);
void		do_pb(t_list *a, t_list *b);
void		do_ra(t_list *a);
void		do_rb(t_list *b);
void		do_rr(t_list *a, t_list *b);
void		do_rra(t_list *a);
void		do_rrb(t_list *b);
void		do_rrr(t_list *a, t_list *b);
int			is_sorted(t_list *a);

#endif
