/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:25:55 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/23 14:25:56 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_clear(t_node *target)
{
	target->next = NULL;
	target->prev = NULL;
	target->value = 0;
	free (target);
	target = NULL;
}
