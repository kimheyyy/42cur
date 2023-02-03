/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:58:50 by hwankim           #+#    #+#             */
/*   Updated: 2023/01/30 14:37:18 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*wrap_malloc(size_t s)
{
	void	*ret;

	ret = malloc(s);
	if (ret == NULL)
	{
		write(1, "Malloc Error ", 13);
		exit(1);
	}
	return (ret);
}

void	check_fd(t_param *par, char *filename)
{
	par->fd = open(filename, O_RDONLY);
	if (par->fd < 0)
		print_error(par, "FILE OPEN ERROR");
	map_to_par(par);
}

int	map_check(t_param *par)
{
	int	i;
	int	j;

	i = 0;
	while (par->map_arr[i])
	{
		j = 0;
		while (par->map_arr[i][j])
		{
			if (par->map_arr[0][j] != '1' || \
				par->map_arr[par->height - 1][j] != '1' \
				|| par->map_arr[i][0] != '1'
				|| par->map_arr[i][par->width - 1] != '1')
				print_error(par, "NOT VALID A MAP");
			if (par->map_arr[i][j] != '0' && par->map_arr[i][j] != '1'
				&& par->map_arr[i][j] != 'C' && par->map_arr[i][j] != 'E'
				&& par->map_arr[i][j] != 'P')
				print_error(par, "NOT VALID A MAP");
			j++;
		}
		i++;
	}
	return (1);
}

void	size_check_map(t_param *par)
{
	int	temp_cor_count;
	int	col_count;
	int	row_count;

	row_count = 0;
	temp_cor_count = 0;
	while (par->map_arr[0][temp_cor_count])
		temp_cor_count++;
	while (par->map_arr[row_count])
	{
		col_count = 0;
		while (par->map_arr[row_count][col_count])
			col_count++;
		if (temp_cor_count != col_count)
			print_error(par, "MAP IS NOT RECTANGLE");
		row_count++;
	}
	par->width = col_count;
	par->height = row_count;
	par->win_width = par->wi * col_count;
	par->win_height = par->he * row_count;
}
