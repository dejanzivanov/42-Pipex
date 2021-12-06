/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 06:28:49 by dzivanov          #+#    #+#             */
/*   Updated: 2021/12/05 06:33:31 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_double_close(int (*fd)(int), int (*ft)(int), t_helper **help)
{
	fd((*help)->fd[0]);
	ft((*help)->fd[1]);
}

void	ft_pid_helper(int (*fd)(int *), __pid_t (*f)(void), t_helper **help)
{
	fd((*help)->fd);
	(*help)->pid = f();
	ft_pid_check((*help)->pid);
}

void	ft_file_creator(char **argv, int argc)
{
	int	file;

	file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	close(file);
}

void	ft_argument_check(int argc, t_helper **help)
{
	if (argc < 5)
	{
		write(2, "Incorrect Number of Arugments\n", 30);
		free(*help);
		exit(0);
	}
}

void	ft_last_cmd(t_list *cmd_list, t_helper **help)
{
	waitpid((*help)->pid, NULL, 0);
	dup2((*help)->fd[0], STDIN_FILENO);
	close((*help)->fd[0]);
	close((*help)->fd[1]);
	if (execve(((t_content *)(cmd_list->content))->path, \
		((t_content *)(cmd_list->content))->cmd_n_flags, __environ) == -1)
	{
		perror("Command was not executed");
		ft_file_descriptor_killer();
		exit(EXIT_FAILURE);
	}
}
