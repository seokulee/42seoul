/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:25:53 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/23 14:25:54 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = list_new();
	b = list_new();
	if (!get_data(argc, argv, a))
	{
		write(1, "Error!\n", 7);
		exit(0);
	}
	sort(a, b);
	list_clear(a);
	list_clear(b);
}