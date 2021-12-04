/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 05:18:43 by dzivanov          #+#    #+#             */
/*   Updated: 2021/12/03 23:27:14 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_inputfile_checker(char *filename)
{
	if (access(filename, F_OK) == 0)
	{
		if (access(filename, R_OK) == 0)
			return ;
		else
		{
			perror("Input file without reading rights");
			ft_file_descriptor_killer();
			exit(0);
		}
	}
	else
	{
		perror("Invalid Input File");
		ft_file_descriptor_killer();
		exit(0);
	}
}

void	ft_outputfile_checker(const char *filename)
{
	if (access(filename, F_OK) == 0)
	{
		if (access(filename, W_OK) != 0)
		{
			perror("Output file without writing rights");
			ft_file_descriptor_killer();
			exit(0);
		}
	}
	else
		return ;
}
