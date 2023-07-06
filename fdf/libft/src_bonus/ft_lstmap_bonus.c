/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:16:29 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/20 14:24:03 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*value;
	t_list	*ptr;

	if (!lst || !f)
		return (NULL);
	result = NULL;
	while (lst)
	{
		ptr = f(lst->content);
		value = ft_lstnew(ptr);
		if (!value)
		{
			del(ptr);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, value);
		lst = lst->next;
	}
	return (result);
}
