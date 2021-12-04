/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 05:54:02 by dzivanov          #+#    #+#             */
/*   Updated: 2021/12/03 23:08:02 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*return_s;

	if (!s1 || !s2)
		return (NULL);
	return_s = ft_calloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1, 1);
	if (return_s == NULL)
		return (NULL);
	ft_memcpy(return_s, s1, ft_strlen(s1));
	ft_memcpy(return_s + ft_strlen(s1), s2, ft_strlen(s2));
	free (s1);
	return (return_s);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free_list(t_list *head)
{
	t_list	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		ft_free_split(((t_content *)(tmp->content))->cmd_n_flags);
		if (((t_content *)(tmp->content))->path != NULL)
			free(((t_content *)(tmp->content))->path);
		else
			continue ;
		free(tmp->content);
		free(tmp);
	}
}

void	ft_free_and_exit(t_list **cmd_list)
{
	ft_free_list(*cmd_list);
	ft_file_descriptor_killer();
	exit(1);
}

void	ft_safety_check(int i)
{
	if (i < 0)
	{
		perror("Return Value -1 detected");
		exit(EXIT_FAILURE);
	}
}
