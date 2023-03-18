/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghol <jeonghol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:58:54 by jeonghol          #+#    #+#             */
/*   Updated: 2023/01/29 15:20:11 by jeonghol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "datatype.h"

t_entry	*entry_init(char *path);
void	solution_1(t_entry *entry, char *str);

int	main(int argc, char *argv[])
{
	int		fd;
	t_entry	*head;

	fd = -1;
	head = NULL;
	if (argc == 2)
	{
		fd = open("number.dict", O_RDWR);
		head = entry_init("number.dict");
		solution_1(head, argv[1]);
	}
	else if (argc == 3)
	{
		fd = open(argv[1], O_RDWR);
		head = entry_init(argv[1]);
		solution_1(head, argv[2]);
	}
	close(fd);
	free(head);
	return (0);
}
