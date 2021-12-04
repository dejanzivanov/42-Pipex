/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 06:19:19 by dzivanov          #+#    #+#             */
/*   Updated: 2021/12/04 00:21:11 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_last_cmd(pid_t pid, int output, t_list *cmd_list, int *p)
{
	waitpid(pid, NULL, 0);
	dup2(p[0], STDIN_FILENO);
	close(p[0]);
	close(output);
	close(p[1]);
	if (execve(((t_content *)(cmd_list->content))->path, \
		((t_content *)(cmd_list->content))->cmd_n_flags, __environ) == -1)
	{
		perror("Command not found.");
		exit(EXIT_FAILURE);
	}
}

void	ft_double_safety_check(int i, int y)
{
	if ((i < 0) || (y < 0))
	{
		perror("Return Value -1 detected");
		exit(EXIT_FAILURE);
	}
}

void	ft_file_descriptor_killer(void)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	exit(EXIT_FAILURE);
}
