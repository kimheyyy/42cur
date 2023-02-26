/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:04:48 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 16:39:40 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	ft_atoi(char *arg)
{
	int			i;
	int			sign;
	long long	value;

	if (!check_input(arg))
		print_error();
	i = 0;
	sign = 1;
	value = 0;
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i++] == '-')
			sign = -1;
	}
	while (arg[i])
		value = value * 10 + (arg[i++] - '0');
	value = value * sign;
	if (value > MAX_INT || value < MIN_INT)
		print_error();
	return (value);
}
