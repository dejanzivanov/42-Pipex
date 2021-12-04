/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 04:56:51 by dzivanov          #+#    #+#             */
/*   Updated: 2021/12/03 04:56:51 by dzivanov         ###   ########.fr       */
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

void	ft_cmd_exec(t_list *cmd_list)
{
	if (execve(((t_content *)(cmd_list->content))->path, \
	((t_content *)(cmd_list->content))->cmd_n_flags, __environ) \
	== -1)
	{
		perror("Command execution failed");
		ft_file_descriptor_killer();
	}
}

void	ft_pipe(int argc, char **argv, t_list *cmd_list, int j)
{	//pitaj sutra za j - jer potrebno ili ne, visak inkremental ili sta, da li moze da se brise, ili da se promeni sa I
	int		p[2];
	pid_t	pid;
	int		output;
	int		i;

	i = 0;
	p[0] = open(argv[j + 1], O_RDONLY);
	output = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	p[1] = output;
	dup2(p[0], STDIN_FILENO);
	dup2(p[1], STDOUT_FILENO);
	close(p[0]);
	while (i < argc - 3 - 1)
	{
		pipe(p);
		pid = fork();
		ft_pid_check(pid);
		if (pid == 0)
		{
			ft_fd_close(p[0], output);
			if (cmd_list->next != NULL)
			{
				dup2(p[1], STDOUT_FILENO);
				close(p[1]);
			}
			ft_cmd_exec(cmd_list);
		}
		else
		{
			waitpid(pid, NULL, 0);
			errno = 0;
			close(p[1]);
			dup2(p[0], STDIN_FILENO);
			close(p[0]);
			if (cmd_list->next != NULL)
				cmd_list = cmd_list->next;
			i++;
		}
		if (i == argc - 3 - 1)
			ft_last_cmd(pid, output, cmd_list, p);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_list	*cmd_list;

	cmd_list = NULL;
	i = 0;
	while (argv[i])
	{
		if (((ft_strncmp(argv[i], "./pipex", ft_strlen("./pipex")) == 0)))
			break ;
		i++;
	}
	if (i > 0)
		i--;
	ft_inputfile_checker(argv[i + 1]);
	ft_outputfile_checker(argv[argc - 1]);
	ft_cmd_check(argv, i, envp, argc, &cmd_list);
	ft_pipe(argc, argv, cmd_list, 0);
	return (0);
}
