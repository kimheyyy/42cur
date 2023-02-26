/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:06:41 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/22 14:34:36 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	setting(t_files *files, int argc, char *argv[], char *envp[])
{
	files->argc = argc;
	files->input_index = 2;
	if (pipe(files->read_pi) == -1)
		ft_perror("pipe error", 1);
	close(files->read_pi[WRITE]);
	get_path(files, envp);
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		files->outfile = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (files->outfile == -1)
			ft_perror(argv[argc - 1], 1);
		here_doc(files, argv);
	}
	else
	{
		files->infile = open(argv[1], O_RDONLY);
		if (files->infile == -1)
			perror(argv[1]);
		files->outfile = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (files->outfile == -1)
			ft_perror(argv[argc - 1], 1);
	}
}

void	ft_perror(char *msg, int exit_status)
{
	perror(msg);
	exit(exit_status);
}
