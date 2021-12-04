/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 05:49:20 by dzivanov          #+#    #+#             */
/*   Updated: 2021/12/03 23:14:05 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_free_elements(char **path_splits, t_list **cmd_list, \
						t_content *content, t_list *elem)
{
	ft_free_split(path_splits);
	ft_free_list(*cmd_list);
	free(content);
	free(elem);
	ft_file_descriptor_killer();
	perror("Invalid Command");
	exit(1);
}

char	*ft_path_check(char **path, char **split, int j, const char *cmd)
{
	*path = ft_strjoin_free(ft_strjoin(split[j], "/"), cmd);
	if (access(*path, F_OK) == 0)
	{
		return (*path);
	}
	else if (access(*path, F_OK) == -1)
	{
		free(*path);
		*path = NULL;
		return (*path);
	}
	return (*path);
}

char	*ft_get_cmd_path(const char *cmd, char **path_split)
{
	int		j;
	char	*path;

	j = 0;
	path = NULL;
	while (path_split[j] != NULL)
	{
		if (ft_path_check(&path, path_split, j, cmd) != NULL)
			return (path);
		j++;
	}
	return (path);
}

char	**ft_split_path(char **env)
{
	int		i;
	char	**split;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_memcmp(env[i], "PATH=", 5) == 0)
		{
			split = ft_split(ft_strchr(env[i], '/'), ':');
			return (split);
		}
		i++;
	}
	ft_file_descriptor_killer();
	exit(1);
}

void	ft_cmd_check(char **argv, int i, char **envp, \
					int argc, t_list **cmd_list)
{
	t_content	*content;
	t_list		*elem;
	char		**path_splits;
	int			j;

	j = 0;
	path_splits = ft_split_path(envp);
	while (i + 2 <= argc - 2)
	{
		content = ft_calloc(1, sizeof(t_content));
		content->cmd_n_flags = ft_split(argv[i + 2], ' ');
		content->path = ft_get_cmd_path(content->cmd_n_flags[0], path_splits);
		content->index = j;
		elem = ft_lstnew(content);
		ft_lstadd_back(cmd_list, elem);
		if (content->path == NULL)
			ft_free_elements(path_splits, cmd_list, content, elem);
		j++;
		i++;
	}
	ft_free_split(path_splits);
}
