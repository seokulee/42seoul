/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:24:17 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/25 15:07:54 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "push_swap_common.h"

void		sort(t_list *a, t_list *b);
void		sort_a(t_list *a, t_list *b, int cnt, int opt);
void		sort_small_a(t_list *lst, int cnt);
void		sort_b(t_list *a, t_list *b, int cnt, int opt);
void		sort_small_b(t_list *lst, int cnt);
void		set_pivot(t_list *lst, int cnt, int *p1, int *p2);
void		set_pivot5(t_list *lst, int cnt, int *p);
void		rrr_controler(int cmd[], t_list *a, t_list *b, int opt);
void		quicksort(t_list *lst, t_node *head, t_node *tail);

#endif
