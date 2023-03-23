/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:21:59 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/18 18:18:38 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;

	if (len == 0 || dst == src)
		return (dst);
	c_dst = dst;
	c_src = (unsigned char *) src;
	while (len--)
	{
		if (c_src > c_dst)
			*c_dst++ = *c_src++;
		else
			*(c_dst + len) = *(c_src + len);
	}
	return (dst);
}
