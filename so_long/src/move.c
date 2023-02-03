/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:49:55 by hwankim           #+#    #+#             */
/*   Updated: 2023/01/30 14:29:02 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_p(t_param *par)
{
	int	i;
	int	j;

	j = -1;
	par->p_x = 0;
	par->p_y = 0;
	while (par->map_arr[++j])
	{
		i = -1;
		while (par->map_arr[j][++i])
		{
			if (par->map_arr[j][i] == 'P')
			{
					par->p_x = i;
					par->p_y = j;
			}
		}
	}
}

int	get_e(t_param *par)
{
	if (par->count_c == 0)
	{
		par->move++;
		write(1, "GAME FINISH! ", 13);
		print_move(par);
		system ("leaks so_long");
		map_free(par->map_arr);
		system ("leaks so_long");
		exit(0);
	}
	else
		return (1);
}

void	examine_map_char(t_param *par)
{
	int			i;
	int			j;

	j = -1;
	while (par->map_arr[++j])
	{
		i = -1;
		while (par->map_arr[j][++i] != '\0')
		{
			if (par->map_arr[j][i] == 'E')
				par->count_e++;
			else if (par->map_arr[j][i] == 'P')
				par->count_p++;
			else if (par->map_arr[j][i] == 'C')
				par->count_c++;
		}
	}
	if (par->count_e != 1 || par->count_p != 1 || par->count_c < 1)
		print_error(par, "유효하지 않은 맵");
}
