/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:58:05 by hwankim           #+#    #+#             */
/*   Updated: 2023/01/30 10:58:26 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_param		par;

	set_param(&par);
	if (argc != 2)
		print_error(&par, "Please one parameter!\n");
	if (!check_filename(argv[1]))
		print_error(&par, "Unable filename!\n");
	check_fd(&par, argv[1]);
	set_p(&par);
	size_check_map(&par);
	if (map_check(&par))
		examine_map_char(&par);
	par.win = mlx_new_window(par.mlx, par.win_width, par.win_height, "so_long");
	dfs_check(par);
	draw_entire(&par);
	mlx_key_hook(par.win, &key_press, &par);
	mlx_hook(par.win, PRESS_RED_BUTTON, 0, &redbut, &par);
	mlx_loop(par.mlx);
}
