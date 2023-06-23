/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:41:52 by seokklee          #+#    #+#             */
/*   Updated: 2023/06/21 13:45:00 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_pipes(t_pack *pack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_close(pack->pipe_fd[i][0]);
		ft_close(pack->pipe_fd[i][1]);
		i++;
	}
}

void	ft_close(int fd)
{
	if (close(fd) < 0)
		error_msg_no(ERR_CLOSE);
}

void	ft_wait_child(t_pack *pack, int level)
{
	int	i;

	i = 0;
	while (i++ < level)
		ft_wait();
	waitpid(pack->pid[level], &pack->status, 0);
}

void	ft_wait(void)
{
	if (wait(NULL) < 0)
		error_msg_no(ERR_WAIT);
}
