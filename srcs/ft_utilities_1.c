/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 06:27:02 by dzivanov          #+#    #+#             */
/*   Updated: 2021/12/08 01:54:17 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_pid_check(int i)
{
	if (i < 0)
	{
		ft_file_descriptor_killer();
	}
}

void	ft_fd_close(int x, int y)
{
	close(x);
	close(y);
}

void	ft_cmd_exec(t_list *cmd_list, t_helper **help)
{
	if (execve(((t_content *)(cmd_list->content))->path, \
	((t_content *)(cmd_list->content))->cmd_n_flags, (*help)->envp) == -1)
	{
		perror("Command execution failed");
		ft_file_descriptor_killer();
		exit(EXIT_FAILURE);
	}
}

void	ft_setup_help(t_helper **help, char **argv, int argc, int j)
{
	(*help)->pid = 0;
	(*help)->fd[0] = open(argv[j + 1], O_RDONLY);
	(*help)->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
}

void	ft_dup_close_out(int (*ft)(int, int), int (*fd)(int), int i)
{
	ft(i, STDOUT_FILENO);
	fd(i);
}
