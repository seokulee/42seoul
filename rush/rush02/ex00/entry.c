/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghol <jeonghol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:58:54 by jeonghol          #+#    #+#             */
/*   Updated: 2023/01/29 15:19:06 by jeonghol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "datatype.h"

void	insert_key(t_entry	*entry, char *str);
void	insert_value(t_entry *entry, char *str);
void	insert_entry(t_entry *entry, char *str);
void	parsing_files(t_entry *head, char *path);
int		line_count_file(char *path);
t_entry	*entry_init(char *path);

void	insert_key(t_entry	*entry, char *str)
{
	int	size;
	int	i;

	size = 0;
	while (str[size] != ':' && str[size] != ' ')
		size++;
	entry -> key = (char *)malloc(sizeof(char) * size + 1);
	i = 0;
	while (i < size)
	{
		entry -> key[i] = str[i];
		i++;
	}
	entry -> key[i] = '\0';
}

void	insert_value(t_entry *entry, char *str)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size = 0;
	while (str[i] != ':')
		i++;
	while (str[i] == ' ' || str[i] == ':')
		i++;
	while (str[i + size] != ' ' && str[i + size] != '\0')
		size++;
	entry -> value = (char *)malloc(sizeof(char) * size + 1);
	while (j < size)
	{
		entry -> value[j] = str[i + j];
		j++;
	}
	entry -> value[j] = '\0';
}

void	insert_entry(t_entry *entry, char *str)
{
	insert_key(entry, str);
	insert_value(entry, str);
}

t_entry	*entry_init(char *path)
{
	int		line_count;
	t_entry	*head;

	line_count = line_count_file(path);
	head = (t_entry *)malloc(sizeof(t_entry) * (line_count + 1));
	head[line_count].key = NULL;
	parsing_files(head, path);
	return (head);
}
