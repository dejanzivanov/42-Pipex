/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 04:57:20 by dzivanov          #+#    #+#             */
/*   Updated: 2021/12/03 04:57:20 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/incl/libft.h"
# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_content
{
	char	**cmd_n_flags;
	char	*path;
	int		index;
}	t_content;

void	ft_inputfile_checker(char *filename);
void	ft_outputfile_checker(const char *filename);
char	*ft_get_cmd_path(const char *cmd, char **path_split);
char	**ft_split_path(char **env);
void	ft_cmd_check(char **argv, int i, char **envp, \
					int argc, t_list **cmd_list);
char	*ft_path_check(char **path, char **split, int j, const char *cmd);
void	ft_free_elements(char **path_splits, t_list **cmd_list, \
						t_content *content, t_list *elem);
char	*ft_strjoin_free(char *s1, char const *s2);
void	ft_free_split(char **split);
void	ft_free_list(t_list *head);
void	ft_safety_check(int i);
void	ft_free_and_exit(t_list **cmd_list);
void	ft_file_opener(int *input, int *output, int argc, char **argv);
void	ft_last_cmd(pid_t pid, int output, t_list *cmd_list, int *p);
void	ft_double_safety_check(int i, int y);
void	ft_file_descriptor_killer(void);

#endif