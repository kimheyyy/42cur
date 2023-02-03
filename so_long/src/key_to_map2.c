/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_to_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:47:31 by hwankim           #+#    #+#             */
/*   Updated: 2023/01/30 11:05:48 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_left_if(t_param *par,	int x, int y)
{
	if (par->map_arr[y][x - 1] == 'C')
		par->count_c--;
	return ;
}

void	move_right_if(t_param *par, int x, int y)
{
	if (par->map_arr[y][x + 1] == 'C')
		par->count_c-- ;
	return ;
}

void	move_up_if(t_param *par, int x, int y)
{
	if (par->map_arr[y - 1][x] == 'C')
		par->count_c--;
	return ;
}

void	move_down_if(t_param *par, int x, int y)
{
	if (par->map_arr[y + 1][x] == 'C')
		par->count_c--;
	return ;
}
