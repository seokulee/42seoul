/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokklee <seokklee@student.42seoul.kr M    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:37:47 by seokklee          #+#    #+#             */
/*   Updated: 2023/06/21 13:51:37 by seokklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ---dependencies--- */
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>

/* ---error msg--- */
# define ERR_ARGC "Numbers of Arguments are not available"
# define ERR_PIPE "Pipe error!"
# define ERR_FORK "Fork error!"
# define ERR_CLOSE "Close error!"
# define ERR_OPEN "Open error!"
# define ERR_OUTPUT "Output file error!"
# define ERR_DUP2 "Dup2 error!"
# define ERR_EXECVE "Execve error!"
# define ERR_CMD "command not found"
# define ERR_WAIT "Wait error!"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_pack
{
	char	**argv;
	char	**envp;
	char	**path_tab;
	int		n_cmd;
	int		cmd_seq;
	int		input_file;
	int		output_file;
	pid_t	pid[256];
	int		pipe_fd[256][2];
	int		here_doc;
	char	*escape;
	char	*tmp;
	int		status;
}	t_pack;

/* --functions-- */
void	exe_cmd(t_pack *pack, int level);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	ft_pipe(t_pack *pack, int level);
void	ft_fork(t_pack *pack, int level);
void	ft_dup2(int from_fd, int to_fd);
void	ft_execve(t_pack *pack);
void	ft_open(char *file_name, int *fd);
void	ft_output_file(char *file_name, int *fd);
void	ft_close_pipes(t_pack *pack, int n);
void	ft_close(int fd);
void	ft_wait_child(t_pack *pack, int level);
void	ft_wait(void);

char	*get_cmd(char **path_tab, char *cmd_uncertain);
char	*get_path(char *envp[]);
void	init_pack(t_pack *pack, int argc, char *argv[], char *envp[]);
char	**ft_split(char const *s, char c);
char	**ft_free_tab(char **tab);

int		error_msg(char *msg);
int		error_msg_no(char *msg);

/* --bonus-- */
void	get_stdin(t_pack *pack);
void	exe_cmd_hd(t_pack *pack, int level);
void	ft_execve_hd(t_pack *pack);
void	ft_output_file_hd(char *file_name, int *fd);
void	heredoc_file_ctr(t_pack *pack);
void	ft_connect_fd(t_pack *pack);

/* --gnl-- */
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_get_line(int fd, char **backup, char *buffer);
size_t	ft_find_nl_idx(char *backup_fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_seperate(int fd, char **backup);
char	*ft_eof(int fd, char **backup);

#endif