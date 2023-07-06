/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:05:15 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/18 18:20:16 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	rear;
	char	*result;

	front = 0;
	rear = ft_strlen(s1);
	if (rear < 2)
		return (ft_strdup(""));
	while (*(s1 + front) && ft_strchr(set, *(s1 + front)))
		front++;
	while (*(s1 + rear - 1) && ft_strchr(set, *(s1 + rear - 1)))
		rear--;
	if (front >= rear)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (rear - front + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + front, rear - front + 1);
	return (result);
}
