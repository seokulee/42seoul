/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:38:34 by seokklee          #+#    #+#             */
/*   Updated: 2023/01/19 20:28:35 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = 0;
	while (*dest)
	{
		dest++;
		dest_len++;
	}
	src_len = 0;
	while (*src && dest_len + src_len + 1 < size)
	{
		*dest++ = *src++;
		src_len++;
	}
	while (*src++)
		src_len++;
	*dest = '\0';
	if (size <= dest_len)
		return (src_len + size);
	else
		return (src_len + dest_len);
}
