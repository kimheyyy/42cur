/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:07:19 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/22 12:07:20 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define READ 0
# define WRITE 1

typedef struct s_files
{
	int		infile;
	int		outfile;
	char	**path;
	char	**cmd_options;
	char	**cmd_options2;
	char	*first_cmd;
	char	*second_cmd;
}			t_files;

void	ft_perror(char *msg, int exit_status);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_close(int fd, int fd2);
void	ft_dup2(int fd, int fd2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);

#endif