/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:36:44 by seokklee          #+#    #+#             */
/*   Updated: 2023/06/21 13:36:45 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pack(t_pack *pack, int argc, char *argv[], char *envp[])
{
	pack->argv = argv;
	pack->envp = envp;
	pack->path_tab = ft_split(get_path(envp), ':');
	pack->n_cmd = argc - 3;
	pack->cmd_seq = 0;
	pack->status = 0;
	ft_open(pack->argv[1], &pack->input_file);
	ft_output_file(pack->argv[pack->n_cmd + 2], &pack->output_file);
}
