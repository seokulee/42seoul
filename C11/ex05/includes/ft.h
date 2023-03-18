/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:21:30 by seokklee          #+#    #+#             */
/*   Updated: 2023/02/02 11:07:05 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		ft_atoi(char *str);
int		add(int n1, int n2);
int		sub(int n1, int n2);
int		mul(int n1, int n2);
int		div(int n1, int n2);
int		mod(int n1, int n2);
void	ft_do_op(char *num1, char *op, char *num2);
int		ft_is(char *c, char *s);
void	ft_printerr(int i);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_strlen(char *s);

#endif
