/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 05:18:43 by dzivanov          #+#    #+#             */
/*   Updated: 2021/12/06 15:04:20 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_inputfile_checker(char *filename, char **argv, int argc, \
							t_helper **help)
{
	if (access(filename, F_OK) == 0)
	{
		if (access(filename, R_OK) == 0)
			return ;
		else
		{
			ft_file_creator(argv, argc);
			perror("Input file without reading rights");
			free(*help);
			ft_file_descriptor_killer();
			exit(0);
		}
	}
	else
	{
		ft_file_creator(argv, argc);
		perror("Invalid Input File");
		free(*help);
		ft_file_descriptor_killer();
		exit(0);
	}
}

void	ft_outputfile_checker(const char *filename, t_helper **help)
{
	if (access(filename, F_OK) == 0)
	{
		if (access(filename, W_OK) != 0)
		{
			free(*help);
			perror("Output file without writing rights");
			ft_file_descriptor_killer();
			exit(0);
		}
	}
	else
		return ;
}
