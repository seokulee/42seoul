/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghol <jeonghol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:58:54 by jeonghol          #+#    #+#             */
/*   Updated: 2023/01/29 15:20:23 by jeonghol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatype.h"
#include <unistd.h>
#include <stdlib.h>

char	*trim(char *str);
void	ft_putstr(char *str);
t_entry	*find_by_key(t_entry *entry, char *key);

void	solution_1(t_entry *entry, char *str)
{
	char	*key;
	t_entry	*find_one;

	key = trim(str);
	if (key == 0)
		return ;
	find_one = find_by_key(entry, key);
	if (find_one)
		ft_putstr(find_one -> value);
}
