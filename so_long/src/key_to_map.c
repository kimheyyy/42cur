/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_to_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:47:17 by hwankim           #+#    #+#             */
/*   Updated: 2023/01/30 11:05:33 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_press(int keycode, t_param *par)
{
	if (keycode == KEY_W)
		move_up(par, par->p_x, par->p_y);
	else if (keycode == KEY_S)
		move_down(par, par->p_x, par->p_y);
	else if (keycode == KEY_A)
		move_left(par, par->p_x, par->p_y);
	else if (keycode == KEY_D)
		move_right(par, par->p_x, par->p_y);
	else if (keycode == KEY_ESC)
		esc_press(keycode, par);
	draw_entire(par);
	return (0);
}

void	move_left(t_param *par, int x, int y)
{
	if (par->map_arr[y][x - 1] == '1')
		return ;
	else if (par->map_arr[y][x - 1] == 'E')
		if (get_e(par))
			return ;
	move_left_if(par, x, y);
	par->map_arr[y][x - 1] = 'P';
	par->map_arr[y][x] = '0';
	par->move++;
	set_p(par);
	print_move(par);
}

void	move_right(t_param *par, int x, int y)
{
	if (par->map_arr[y][x + 1] == '1')
		return ;
	else if (par->map_arr[y][x + 1] == 'E')
		if (get_e(par))
			return ;
	move_right_if(par, x, y);
	par->map_arr[y][x + 1] = 'P';
	par->map_arr[y][x] = '0';
	par->move++;
	set_p(par);
	print_move(par);
}

void	move_up(t_param *par, int x, int y)
{
	if (par->map_arr[y - 1][x] == '1')
		return ;
	else if (par->map_arr[y - 1][x] == 'E')
		if (get_e(par))
			return ;
	move_up_if(par, x, y);
	par->map_arr[y - 1][x] = 'P';
	par->map_arr[y][x] = '0';
	par->move++;
	set_p(par);
	print_move(par);
}

void	move_down(t_param *par, int x, int y)
{
	if (par->map_arr[y + 1][x] == '1')
		return ;
	else if (par->map_arr[y + 1][x] == 'E')
		if (get_e(par))
			return ;
	move_down_if(par, x, y);
	par->map_arr[y + 1][x] = 'P';
	par->map_arr[y][x] = '0';
	par->move++;
	set_p(par);
	print_move(par);
}
