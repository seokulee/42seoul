/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stdin_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:37:14 by seokklee          #+#    #+#             */
/*   Updated: 2023/06/23 14:11:39 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_stdin(t_pack *pack)
{
	char	*line;

	write(1, "here_doc> ", 10);
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp(line, pack->escape, ft_strlen(line)))
			break ;
		write(pack->input_file, line, ft_strlen(line));
		free(line);
		write(1, "here_doc> ", 10);
		line = get_next_line(0);
	}
	free(line);
	free(pack->escape);
	ft_close(pack->input_file);
	ft_open(pack->tmp, &pack->input_file);
	unlink(pack->tmp);
	free(pack->tmp);
}
