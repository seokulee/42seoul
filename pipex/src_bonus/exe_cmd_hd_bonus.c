/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd_hd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:36:58 by seokklee          #+#    #+#             */
/*   Updated: 2023/06/21 13:47:07 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe_cmd_hd(t_pack *pack, int level)
{
	if (level > pack->n_cmd - 1)
		return ;
	pack->cmd_seq = level;
	ft_pipe(pack, level);
	ft_fork(pack, level);
	if (pack->pid[level] == 0)
		ft_execve_hd(pack);
	else if (pack->pid[level] > 0)
	{
		if (level == pack->n_cmd - 1)
		{
			ft_close_pipes(pack, level);
			ft_wait_child(pack, level);
		}
		exe_cmd_hd(pack, level + 1);
	}
}

void	ft_execve_hd(t_pack *pack)
{
	char	*cmd;
	char	**cmd_tab;

	ft_connect_fd(pack);
	cmd_tab = ft_split(pack->argv[pack->cmd_seq + 3], ' ');
	cmd = get_cmd(pack->path_tab, cmd_tab[0]);
	if (!cmd)
		error_msg_no(ERR_CMD);
	if (execve(cmd, cmd_tab, pack->envp) < 0)
		error_msg_no(ERR_EXECVE);
}
