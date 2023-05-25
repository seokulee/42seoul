/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:08:00 by seokklee          #+#    #+#             */
/*   Updated: 2023/05/25 15:08:01 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <limits.h>
# include "push_swap_common.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_get_line(int fd, char **backup, char *buffer);
size_t	ft_find_nl_idx(char *backup_fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_seperate(int fd, char **backup);
char	*ft_eof(int fd, char **backup);
void	checker(t_list *a, t_list *b);

#endif
