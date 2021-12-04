/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 05:25:14 by dzivanov          #+#    #+#             */
/*   Updated: 2021/12/03 22:58:52 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"
#include "../../incl/pipex.h"

void	ft_printlist(t_list *begin)
{
	t_list	*ptr;

	ptr = begin;
	while (ptr != NULL)
	{
		ft_putstr_fd((char *)((t_content *)(ptr->content))->path, 2);
		ptr = ptr->next;
	}
	write(2, "\n", 1);
}
