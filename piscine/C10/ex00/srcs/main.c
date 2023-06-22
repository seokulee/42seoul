/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:34:42 by seokklee          #+#    #+#             */
/*   Updated: 2023/02/02 15:08:51 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	int	n;
	char buf[100];
	char *st;

	if (argc == 1)
		printf("1");
	else if (argc >= 3)
		printf("2");
	else
	{
		st = argv[1];
		fd = open(st, O_RDONLY);
		n = read(fd, buf, 99);
		printf("n = %d\n", n);
		printf("buf = %s\n", buf);
		close(fd);
	}
}
