/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:21:50 by seokklee          #+#    #+#             */
/*   Updated: 2023/08/06 11:31:37 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	terminate(char *err, int n)
{
	printf("%s", err);
	return (n);
}

int	main(int argc, char *argv[])
{
	t_args	args;

	if (argc != 5 && argc != 6)
		return (terminate(ERR_ARGC, 1));
	memset(&args, 0, sizeof(t_args));
	if (init(&args, argc, argv))
		return (terminate(ERR_ARGS, 1));
	if (start_routine(&args))
		return (1);
	return (0);
}
