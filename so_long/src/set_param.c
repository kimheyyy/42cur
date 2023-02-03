/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:54:18 by hwankim           #+#    #+#             */
/*   Updated: 2023/01/30 14:31:17 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_param(t_param *par)
{
	par->wi = 64;
	par->he = 64;
	par->count_e = 0;
	par->count_p = 0;
	par->count_c = 0;
	par->x = 0;
	par->y = 0;
	par->move = 0;
	par->p_x = 0;
	par->p_y = 0;
	par->mlx = mlx_init();
	par->map_arr = NULL;
	if (!par->mlx)
		print_error(par, "MLX INIT ERROR");
	par->g = mlx_xpm_file_to_image (par->mlx, "images/g.xpm", \
	&par->wi, &par->he);
	par->w = mlx_xpm_file_to_image (par->mlx, "images/w.xpm", \
	&par->wi, &par->he);
	par->c = mlx_xpm_file_to_image (par->mlx, "images/c.xpm", \
	&par->wi, &par->he);
	par->e = mlx_xpm_file_to_image (par->mlx, "images/e.xpm", \
	&par->wi, &par->he);
	par->p = mlx_xpm_file_to_image (par->mlx, "images/p.xpm", \
	&par->wi, &par->he);
	par->win = NULL;
}
