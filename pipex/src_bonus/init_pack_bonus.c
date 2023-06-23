/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pack_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:37:20 by seokklee          #+#    #+#             */
/*   Updated: 2023/06/21 13:49:22 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pack(t_pack *pack, int argc, char *argv[], char *envp[])
{
	pack->argv = argv;
	pack->envp = envp;
	pack->path_tab = ft_split(get_path(envp), ':');
	pack->cmd_seq = 0;
	pack->status = 0;
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
	{
		pack->n_cmd = argc - 4;
		pack->escape = ft_strjoin(argv[2], "\n");
		heredoc_file_ctr(pack);
		pack->here_doc = 1;
	}
	else
	{
		pack->n_cmd = argc - 3;
		ft_open(pack->argv[1], &pack->input_file);
		ft_output_file(pack->argv[pack->n_cmd + 2], &pack->output_file);
		pack->here_doc = 0;
	}
}

void	ft_output_file(char *file_name, int *fd)
{
	*fd = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (*fd < 0)
		error_msg_no(ERR_OUTPUT);
}
