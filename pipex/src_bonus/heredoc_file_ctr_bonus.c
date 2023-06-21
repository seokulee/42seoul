/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_file_ctr_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:37:18 by seokklee          #+#    #+#             */
/*   Updated: 2023/06/21 13:50:05 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredoc_file_ctr(t_pack *pack)
{
	pack->tmp = ft_strdup("hd_rd!");
	while (!access(pack->tmp, F_OK))
		pack->tmp[5]++;
	pack->input_file = open(pack->tmp, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (pack->input_file < 0)
		error_msg_no(ERR_OUTPUT);
	ft_output_file_hd(pack->argv[pack->n_cmd + 3], &pack->output_file);
}

void	ft_output_file_hd(char *file_name, int *fd)
{
	*fd = open(file_name, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (*fd < 0)
		error_msg_no(ERR_OUTPUT);
}
