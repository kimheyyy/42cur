/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:07:43 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/22 15:01:05 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_perror(char *msg, int exit_status)
{
	perror(msg);
	exit(exit_status);
}

void	ft_close(int fd, int fd2)
{
	close(fd);
	close(fd2);
}

void	ft_dup2(int fd, int fd2)
{
	if (fd == -1)
	{
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	close(fd);
	close(fd2);
}
