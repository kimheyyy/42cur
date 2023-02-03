/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:00:27 by hwankim           #+#    #+#             */
/*   Updated: 2023/01/30 14:28:55 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"

# define KEY_ESC			53
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2
# define PRESS_RED_BUTTON	17

typedef struct s_checkdfs
{
	int					**visited_arr;
	int					valid_path;
	int					x;
	int					y;
	int					count_c;
}	t_checkdfs;

typedef struct s_param
{
	char		**map_arr;
	void		*mlx;
	void		*win;
	void		*p;
	void		*g;
	void		*w;
	void		*c;
	void		*e;
	int			fd;
	int			x;
	int			y;
	int			wi;
	int			he;
	int			win_width;
	int			win_height;
	int			move;
	int			p_x;
	int			p_y;
	int			count_e;
	int			count_p;
	int			count_c;
	int			width;
	int			height;
}	t_param;

void	map_to_par(t_param *par);
int		draw_entire(t_param *par);
void	esc_press(int keycode, t_param *par);
int		redbut(t_param *par);
int		key_press(int keycode, t_param *par);
int		get_e(t_param *par);
void	set_param(t_param *par);
void	draw_part(char a, t_param *par, int x, int y);
void	set_p(t_param *par);
void	move_left(t_param *par, int x, int y);
void	move_right(t_param *par, int x, int y);
void	move_up(t_param *par, int x, int y);
void	move_down(t_param *par, int x, int y);
void	move_left_if(t_param *par, int x, int y);
void	move_right_if(t_param *par, int x, int y);
void	move_up_if(t_param *par, int x, int y);
void	move_down_if(t_param *par, int x, int y);
char	**ft_split(char const *s, char c);
void	ft_putnbr(int n);
void	ft_putstr_fd(char *s, int fd);
void	print_error(t_param *par, char *message);
void	map_free(char **map);
int		check_filename(char *filename);
void	*wrap_malloc(size_t s);
void	check_fd(t_param *par, char *filename);
void	size_check_map(t_param *par);
int		map_check(t_param *par);
void	examine_map_char(t_param *par);
void	check_map_free(int **map);
int		**copy_map(t_param par);
void	dfs(t_param *par, t_checkdfs *check, int x, int y);
void	dfs_check(t_param par);
void	print_move(t_param *par);
int		ft_strlen_int(char *s);
#endif