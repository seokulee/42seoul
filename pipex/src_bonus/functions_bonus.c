/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:37:03 by seokklee          #+#    #+#             */
/*   Updated: 2023/06/21 13:49:44 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe(t_pack *pack, int level)
{
	if (pipe(pack->pipe_fd[level]) < 0)
		error_msg_no(ERR_PIPE);
}

void	ft_fork(t_pack *pack, int level)
{
	pack->pid[level] = fork();
	if (pack->pid[level] < 0)
		error_msg_no(ERR_FORK);
}

void	ft_dup2(int from_fd, int to_fd)
{
	if (dup2(from_fd, to_fd) < 0)
		error_msg_no(ERR_DUP2);
}

void	ft_connect_fd(t_pack *pack)
{
	if (pack->cmd_seq == 0)
	{
		ft_close(pack->pipe_fd[pack->cmd_seq][0]);
		ft_dup2(pack->input_file, 0);
		ft_dup2(pack->pipe_fd[pack->cmd_seq][1], 1);
	}
	else if (pack->cmd_seq == pack->n_cmd - 1)
	{
		ft_dup2(pack->pipe_fd[pack->cmd_seq - 1][0], 0);
		ft_dup2(pack->output_file, 1);
		ft_close(pack->pipe_fd[pack->cmd_seq][0]);
		ft_close(pack->pipe_fd[pack->cmd_seq][1]);
		ft_close(pack->pipe_fd[pack->cmd_seq - 1][1]);
		ft_close_pipes(pack, pack->cmd_seq - 1);
	}
	else
	{
		ft_dup2(pack->pipe_fd[pack->cmd_seq - 1][0], 0);
		ft_dup2(pack->pipe_fd[pack->cmd_seq][1], 1);
		ft_close(pack->pipe_fd[pack->cmd_seq - 1][1]);
		ft_close(pack->pipe_fd[pack->cmd_seq][0]);
		ft_close_pipes(pack, pack->cmd_seq - 1);
	}
}
