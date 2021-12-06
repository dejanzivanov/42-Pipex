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

void	ft_pid_helper1(int (*dp)(int, int), int (*clo)(int), \
	__pid_t (*wai)(__pid_t, int *, int), t_helper **help)
{
	wai((*help)->pid, NULL, 0);
	clo((*help)->fd[1]);
	dp((*help)->fd[0], STDIN_FILENO);
	clo((*help)->fd[0]);
}

void	ft_pipe(int argc, t_list *cmd_list, t_helper **help)
{
	int	i;

	i = 0;
	ft_double_safety_check(dup2((*help)->fd[0], 0), dup2((*help)->fd[1], 1));
	ft_double_close(&close, &close, help);
	while (i < argc - 3 - 1)
	{
		ft_pid_helper(&pipe, &fork, help);
		if ((*help)->pid == 0)
		{
			close((*help)->fd[0]);
			if (cmd_list->next != NULL)
				ft_dup_close_out(&dup2, &close, (*help)->fd[1]);
			ft_cmd_exec(cmd_list);
		}
		else
		{
			ft_pid_helper1(&dup2, &close, &waitpid, help);
			if (cmd_list->next != NULL)
				cmd_list = cmd_list->next;
			i++;
		}
		if (i == argc - 3 - 1)
			ft_last_cmd(cmd_list, help);
	}
}

int	main(int argc, char **argv)
{
	t_list		*cmd_list;
	t_helper	*help;

	cmd_list = NULL;
	help = ft_calloc(sizeof(t_helper), 1);
	ft_argument_check(argc, &help);
	ft_inputfile_checker(argv[1], argv, argc, &help);
	ft_outputfile_checker(argv[argc - 1]);
	ft_cmd_check(argv, argc, &help, &cmd_list);
	ft_setup_help(&help, argv, argc, 0);
	ft_pipe(argc, cmd_list, &help);
	return (0);
}
