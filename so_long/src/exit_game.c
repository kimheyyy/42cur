/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:46:12 by hwankim           #+#    #+#             */
/*   Updated: 2023/01/30 13:10:24 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	esc_press(int keycode, t_param *par)
{
	if (keycode == KEY_ESC)
		print_error(par, "press ESC button!\n" );
}

int	redbut(t_param *par)
{
	print_error(par, "press red button!\n" );
	return (0);
}

int	ft_strlen_int(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
