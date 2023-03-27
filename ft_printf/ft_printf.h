/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*        printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:51:58 by seokklee          #+#    #+#             */
/*   Updated: 2023/03/26 17:34:35 by seokklee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_parsing(const char *format, va_list ap, int *len);
int	ft_print_char(int c);
int	ft_print_nbr(int n);
int	ft_print_ptr(unsigned long ptr);
int	ft_print_str(char *s);
int	ft_print_hex(long long num, char x);
int	ft_print_u(unsigned int num);

#endif
