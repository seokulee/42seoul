/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:16:29 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/18 09:35:25 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_lst	*new;

	if (!lst || !f)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list) * ft_lstsize(lst));
	if (!new)
	{
		ft_lstclear(new, del);
		return (NULL);
	}
	ft_lstiter(lst, *f);
	new = lst;
	return (new);
}

