/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:36:37 by seokklee          #+#    #+#             */
/*   Updated: 2023/06/21 13:44:52 by seokklee         ###   ########.fr       */
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

void	ft_open(char *file_name, int *fd)
{
	*fd = open(file_name, O_RDONLY);
	if (*fd < 0)
		error_msg_no(ERR_OPEN);
}

void	ft_output_file(char *file_name, int *fd)
{
	*fd = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (*fd < 0)
		error_msg_no(ERR_OUTPUT);
}
