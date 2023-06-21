/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:37:05 by seokklee          #+#    #+#             */
/*   Updated: 2023/06/21 13:37:06 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd(char **path_tab, char *cmd_uncertain)
{
	char	*tmp;
	char	*cmd;

	if (!cmd_uncertain)
		return (NULL);
	while (*path_tab)
	{
		tmp = ft_strjoin(*path_tab, "/");
		cmd = ft_strjoin(tmp, cmd_uncertain);
		free(tmp);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		free(cmd);
		path_tab++;
	}
	return (NULL);
}
