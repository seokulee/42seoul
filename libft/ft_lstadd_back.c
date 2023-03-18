/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 08:49:08 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/18 08:51:26 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	while (*lst->next)
		*lst = *lst->next;
	*lst->next = new;
}
