/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghol <jeonghol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:58:54 by jeonghol          #+#    #+#             */
/*   Updated: 2023/01/29 15:19:56 by jeonghol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "datatype.h"

char	*get_oneline(int before_size, int buf_size, char *path);
void	parsing_files(t_entry *head, char *path);
void	insert_entry(t_entry *entry, char *str);
int		line_count_file(char *path);

// count "number.dict" line
int	line_count_file(char *path)
{
	int		size;
	int		line_count;
	int		fd;
	char	c;

	fd = open(path, O_RDWR);
	line_count = 0;
	size = 0;
	while (read(fd, &c, 1) != 0)
	{
		if (c != '\n')
			size++;
		else
		{
			if (size == 0)
				continue ;
			line_count++;
			size = 0;
		}
	}
	close(fd);
	return (line_count + 1);
}

// readling "number.dict" line by line
void	parsing_files(t_entry *head, char *path)
{
	int		size;
	int		before_size;
	int		index;
	int		fd;
	char	c;

	size = 0;
	index = 0;
	before_size = 0;
	fd = open(path, O_RDWR);
	while (read(fd, &c, 1) != 0)
	{
		if (c != '\n')
			size++;
		else
		{
			if (size == 0)
				continue ;
			insert_entry(&head[index++], get_oneline(before_size, size, path));
			before_size += size + 1;
			size = 0;
		}
	}
	insert_entry(&head[index], get_oneline(before_size, size, path));
	close(fd);
}

char	*get_oneline(int before_size, int buf_size, char *path)
{
	char	*result;
	char	temp;
	int		i;
	int		fd;

	result = (char *)malloc(sizeof(char) * (buf_size + 1));
	result[buf_size] = 0;
	fd = open(path, O_RDWR);
	i = 0;
	while (i < before_size)
	{
		read(fd, &temp, 1);
		i++;
	}
	read(fd, result, buf_size);
	return (result);
}
