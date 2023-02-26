/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_max_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimhwang <gimhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:03:35 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 01:28:31 by gimhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_mid_value_five(int value[])
{
	int	i;
	int	j;
	int	tmp;

	i = 5;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
		{
			if (value[j] > value[j + 1])
			{
				tmp = value[j + 1];
				value[j + 1] = value[j];
				value[j] = tmp;
			}
		}
	}
	return (value[2]);
}

int	setting_value_to_list(t_node *node)
{
	int	i;
	int	value[5];

	i = -1;
	while (++i < 5)
	{
		value[i] = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (get_mid_value_five(value));
}

int	get_min_value(t_node *node, int size)
{
	int	min;

	min = node->value;
	while (size--)
	{
		if (min > node->value)
			min = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (min);
}

int	get_max_value(t_node *node, int size)
{
	int	max;

	max = node->value;
	while (size--)
	{
		if (max < node->value)
			max = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}
