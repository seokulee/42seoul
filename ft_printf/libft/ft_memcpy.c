/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:13:27 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/18 18:18:29 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;

	if (!dst && !src)
		return (NULL);
	c_dst = dst;
	c_src = (unsigned char *)src;
	while (n--)
		*c_dst++ = *c_src++;
	return (dst);
}
