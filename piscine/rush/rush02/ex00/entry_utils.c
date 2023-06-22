/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghol <jeonghol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:58:54 by jeonghol          #+#    #+#             */
/*   Updated: 2023/01/29 15:11:37 by jeonghol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatype.h"
#include <stdlib.h>

int		ft_strcmp(char *s1, char *s2);

t_entry	*find_by_key(t_entry *entry, char *key)
{
	int		i;
	t_entry	*result;

	result = (t_entry *)malloc(sizeof(t_entry *));
	i = 0;
	while (entry[i].key != NULL)
	{
		if (ft_strcmp(entry[i].key, key) == 0)
		{
			result = &entry[i];
			return (result);
		}
		i++;
	}
	return (0);
}
