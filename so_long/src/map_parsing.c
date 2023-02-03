/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:49:26 by hwankim           #+#    #+#             */
/*   Updated: 2023/01/30 13:17:54 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_filename(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (filename[--i] != 'r')
		return (0);
	if (filename[--i] != 'e')
		return (0);
	if (filename[--i] != 'b')
		return (0);
	if (filename[--i] != '.')
		return (0);
	return (1);
}

void	map_to_par(t_param *par)
{
	char	*line;
	char	*save;
	char	*temp;

	line = get_next_line(par->fd);
	if (!line)
		print_error (par, "fail");
	save = ft_strdup("");
	par->width = ft_strlen_int(line) - 1;
	while (line)
	{
		temp = save;
		save = ft_strjoin(save, line);
		free(temp);
		free(line);
		line = get_next_line(par->fd);
		if (ft_strlen_int(line) - 1 != par->width && line != 0)
		{
			free(save);
			print_error(par, "유효하지 않은 맵");
		}
	}
	par->map_arr = ft_split(save, '\n');
	close(par->fd);
	free(save);
}

void	check_map_free(int **map)
{
	int		i;

	i = -1;
	while (map[++i])
	{
		free(map[i]);
	}
	free(map);
}
