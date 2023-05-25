/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:20:49 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/25 15:10:36 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	operator(t_list *a, t_list *b, char *cmd, int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	err(void);

void	checker(t_list *a, t_list *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		operator(a, b, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (is_sorted(a))
	{
		write(1, "OK\n", 3);
		return ;
	}
	write(1, "KO\n", 3);
}

void	operator(t_list *a, t_list *b, char *cmd, int n)
{
	if (!ft_strncmp(cmd, "ra\n", n))
		do_ra(a);
	else if (!ft_strncmp(cmd, "rb\n", n))
		do_rb(b);
	else if (!ft_strncmp(cmd, "rr\n", n))
		do_rr(a, b);
	else if (!ft_strncmp(cmd, "pa\n", n))
		do_pa(a, b);
	else if (!ft_strncmp(cmd, "pb\n", n))
		do_pb(a, b);
	else if (!ft_strncmp(cmd, "rra\n", n))
		do_rra(a);
	else if (!ft_strncmp(cmd, "rrb\n", n))
		do_rrb(b);
	else if (!ft_strncmp(cmd, "rrr\n", n))
		do_rrr(a, b);
	else if (!ft_strncmp(cmd, "sa\n", n))
		do_sa(a);
	else if (!ft_strncmp(cmd, "sb\n", n))
		do_sb(b);
	else if (!ft_strncmp(cmd, "ss\n", n))
		do_ss(a, b);
	else
		err();
}

void	err(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
	}
	return (0);
}
