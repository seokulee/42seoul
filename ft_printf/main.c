/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:32:47 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/26 18:09:52 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

int main ()
{
	char	*s = "sekklee";
	int		i = INT_MAX;
	int		hex=-123;
	int n = ft_printf("hello %% avc int:%d ptr:%p str:%s hex:%x\n", i, s, s, hex);
	int n2 = printf("hello %% avc int:%d ptr:%p str:%s hex:%x\n",i, s, s, hex);
	printf("%d \n", n);
	printf("%d \n", n2);
	return 0;
}