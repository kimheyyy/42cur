/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:06:24 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/26 14:51:44 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	*check_vaild_cmd(char **path, char *cmd)
{
	int		i;
	char	*temp_address;
	char	*path_plus_cmd;
	char	*temp_cmd;

	i = 0;
	path_plus_cmd = NULL;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	temp_cmd = ft_strjoin("/", cmd);
	if (!temp_cmd)
		exit (1);
	while (path[i])
	{
		temp_address = path_plus_cmd;
		path_plus_cmd = ft_strjoin(path[i], temp_cmd);
		free (temp_address);
		if (access(path_plus_cmd, X_OK) == 0)
			return (path_plus_cmd);
		i++;
	}
	return (NULL);
}

void	get_path(t_files *files, char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			envp[i] += 5;
			break ;
		}
		i++;
	}
	files->path = ft_split(envp[i], ':');
}

void	execute(t_files *files, char *argv[], char *envp[])
{
	files->cmd_options = ft_split(argv[files->input_index], ' ');
	if (!files->cmd_options)
		ft_perror("empty string", 1);
	files->cmd = check_vaild_cmd(files->path, files->cmd_options[0]);
	if (!files->cmd)
		ft_perror("not valid cmd", 1);
	if (files->input_index == 2)
	{
		ft_dup2(files->infile, files->write_pi[WRITE]);
		execve(files->cmd, files->cmd_options, envp);
	}
	else if (files->input_index == files->argc - 2)
	{
		ft_dup2(files->read_pi[READ], files->outfile);
		execve(files->cmd, files->cmd_options, envp);
	}
	else
	{
		ft_dup2(files->read_pi[READ], files->write_pi[WRITE]);
		execve(files->cmd, files->cmd_options, envp);
	}
}

void	run_command(t_files *files, char *argv[], char *envp[])
{
	int	fd;

	while (files->input_index < files->argc - 1)
	{
		if (files->input_index != files->argc - 2)
		{
			if (pipe(files->write_pi) == -1)
				ft_perror("pipe error", 1);
		}
		files->pid = fork();
		if (files->pid == -1)
			ft_perror("fork error", 1);
		else if (files->pid == 0)
			execute(files, argv, envp);
		else
		{
			close(files->write_pi[WRITE]);
			fd = files->read_pi[READ];
			files->read_pi[READ] = files->write_pi[READ];
			close(fd);
			files->input_index++;
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_files	files;

	if (argc < 5)
		exit(1);
	setting(&files, argc, argv, envp);
	run_command(&files, argv, envp);
	while (waitpid(files.pid, NULL, WNOHANG) == 0)
		;
	exit(0);
}
