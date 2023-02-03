/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:45:01 by hwankim           #+#    #+#             */
/*   Updated: 2023/01/30 14:30:27 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	**copy_map(t_param par)
{
	int	**map_cp;
	int	i;
	int	j;

	i = 0;
	map_cp = (int **)wrap_malloc (sizeof(int *) * par.height);
	while (i < par.height)
	{
		j = 0;
		map_cp[i] = (int *)wrap_malloc(sizeof(int) * par.width);
		while (j < par.width)
			map_cp[i][j++] = 0;
		i++;
	}
	return (map_cp);
}

void	dfs(t_param *par, t_checkdfs *check, int x, int y)
{
	const int	add_x[4] = {0, 0, -1, 1};
	const int	add_y[4] = {-1, 1, 0, 0};
	int			move_x;
	int			move_y;
	int			i;

	check->visited_arr[y][x] = 1;
	i = 0;
	if (par->map_arr[y][x] == 'C')
			check->count_c--;
	if (par->map_arr[y][x] == 'E')
	{
		check->valid_path = 1;
		return ;
	}
	while (i < 4)
	{
		move_x = x + add_x[i];
		move_y = y + add_y[i];
		if (par->map_arr[move_y][move_x] != '1'\
		&& !check->visited_arr[move_y][move_x])
			dfs(par, check, move_x, move_y);
		i++;
	}
}

void	dfs_check(t_param par)
{
	t_checkdfs	check;
	int			i;

	i = 0;
	check.count_c = par.count_c;
	check.x = par.p_x;
	check.y = par.p_y;
	check.valid_path = 0;
	check.visited_arr = copy_map(par);
	dfs(&par, &check, check.x, check.y);
	if (!check.valid_path || check.count_c)
		print_error(&par, "NOT VALID A MAP");
	while (i < par.height)
		free (check.visited_arr[i++]);
	free (check.visited_arr);
}
