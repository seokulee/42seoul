/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:23:17 by seokklee          #+#    #+#             */
/*   Updated: 2023/08/07 12:20:19 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (start_routine(&args, (&args)->philos))
		return (terminate(ERR_ROUTINE, 1));
	return (0);
}
/* state 를 관장하는 mutex 를 만들어서 barrier, try, spin lock 등을 구현해보자
	atoi부분 쓸데없는 문자열 에러처리
	atoi 후 음수와 0으로 들어오는 매개변수에 대한 에러처리도 있으면 좋을 것 같다.
	must eat 을 지나고 다른 필로가 먹는걸 기다리는 것 외 효과적으로 먹을 수 있는 방법도 구상하기*/
