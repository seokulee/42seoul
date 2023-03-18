/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:05:11 by seokklee          #+#    #+#             */
/*   Updated: 2023/02/01 22:49:21 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) > 0)
		{
			write( fd, strlen(argv[i]));
			close( fd);
		}
		else
			printf("no file");
		i++;
	}
}
