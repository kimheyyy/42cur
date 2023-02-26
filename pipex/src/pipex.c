/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:07:50 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/26 12:46:35 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
	while (path[i])
	{
		temp_address = path_plus_cmd;
		path_plus_cmd = ft_strjoin(path[i], temp_cmd);
		free (temp_address);
		if (access(path_plus_cmd, X_OK) == 0)
		{
			free(temp_cmd);
			return (path_plus_cmd);
		}
		i++;
	}
	free(temp_cmd);
	perror("not valid cmd");
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

void	setting(t_files *files, char *argv[], char *envp[])
{
	files->infile = open(argv[1], O_RDONLY);
	if (files->infile == -1)
		perror(argv[1]);
	files->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (files->outfile == -1)
		ft_perror(argv[4], 1);
	get_path(files, envp);
	files->cmd_options = ft_split(argv[2], ' ');
	files->cmd_options2 = ft_split(argv[3], ' ');
	if (!files->cmd_options)
		perror("empty string");
	else
		files->first_cmd = check_vaild_cmd(files->path, files->cmd_options[0]);
	if (!files->cmd_options2)
		perror("empty string");
	else
		files->second_cmd = \
		check_vaild_cmd(files->path, files->cmd_options2[0]);
}

void	run_command(t_files files, char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_perror("pipe error", 1);
	pid = fork();
	if (pid == -1)
		ft_perror("fork error", 1);
	else if (pid > 0)
	{
		close(fd[WRITE]);
		ft_dup2(fd[READ], files.outfile);
		waitpid(pid, NULL, WNOHANG);
		if (!files.cmd_options2 || !files.second_cmd)
			exit(1);
		execve(files.second_cmd, files.cmd_options2, envp);
	}
	else
	{
		if (!files.cmd_options || !files.first_cmd)
			exit(1);
		close(fd[READ]);
		ft_dup2(files.infile, fd[WRITE]);
		execve(files.first_cmd, files.cmd_options, envp);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_files	files;

	if (argc != 5)
		exit(1);
	setting(&files, argv, envp);
	run_command(files, envp);
}
