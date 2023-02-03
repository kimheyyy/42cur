/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:46:46 by hwankim           #+#    #+#             */
/*   Updated: 2023/01/30 11:04:48 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_part(char a, t_param *par, int x, int y)
{
	mlx_put_image_to_window(par->mlx, par->win, par->g, x * 64, y * 64);
	if (a == '1')
		mlx_put_image_to_window(par->mlx, par->win, par->w, x * 64, y * 64);
	else if (\
	a == 'P' || a == 'C' || a == 'E')
	{
		if (a == 'P')
			mlx_put_image_to_window(par->mlx, par->win, par->p, x * 64, y * 64);
		else if (a == 'C')
			mlx_put_image_to_window(par->mlx, par->win, par->c, x * 64, y * 64);
		else if (a == 'E')
			mlx_put_image_to_window(par->mlx, par->win, par->e, x * 64, y * 64);
	}
}

int	draw_entire(t_param *par)
{
	int			i;
	int			j;

	j = -1;
	mlx_clear_window(par->mlx, par->win);
	while (par->map_arr[++j])
	{
		i = -1;
		while (par->map_arr[j][++i])
		{
			draw_part(par->map_arr[j][i], par, i, j);
		}
	}
	return (0);
}
