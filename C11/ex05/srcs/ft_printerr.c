/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:13:16 by seokklee          #+#    #+#             */
/*   Updated: 2023/02/01 20:30:11 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_printerr(int i)
{
	char	*div_error;
	char	*mod_error;

	div_error = "Stop : division by zero\n";
	mod_error = "Stop : modulo by zero\n";
	if (i == 3)
		ft_putstr(div_error);
	if (i == 4)
		ft_putstr(mod_error);
}
