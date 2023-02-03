/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:51:26 by hwankim           #+#    #+#             */
/*   Updated: 2023/01/30 11:06:46 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	print_error(t_param *par, char *message)
{
	ft_putstr_fd(message, 2);
	if (par->map_arr)
		map_free(par->map_arr);
	exit(1);
}

void	map_free(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
	{
		free(map[i]);
	}
	free(map);
}

void	print_move(t_param *par)
{
	write(1, "MOVE COUNT: ", 12);
	ft_putnbr(par->move);
	write(1, "\n", 1);
}
