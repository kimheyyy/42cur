/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input_three_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimhwang <gimhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:04:50 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 01:37:08 by gimhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	input_three_top_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->next->value == max)
		{
			reverse_rotate_stack(a, A);
			swap_stack(a, A);
		}
	}
	else
	{
		if (a->top->next->value == max)
		{
			rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate_stack(a, A);
		}
	}
}

static void	input_three_middle_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->bottom->value == max)
			swap_stack(a, A);
		else
			rotate_stack(a, A);
	}
	else
	{
		swap_stack(a, A);
		if (a->top->next->value == max)
		{
			rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate_stack(a, A);
		}
	}
}

static void	input_three_bottom_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->value == max)
			swap_stack(a, A);
		reverse_rotate_stack(a, A);
	}
	else
	{
		if (a->top->value == max)
			swap_stack(a, A);
		rotate_stack(a, A);
		swap_stack(a, A);
		reverse_rotate_stack(a, A);
		swap_stack(a, A);
	}
}

void	sort_input_three_a(int r, t_stack *a)
{
	int	min;
	int	max;

	min = get_min_value(a->top, r);
	max = get_max_value(a->top, r);
	if (a->top->value == min)
		input_three_top_min_a(a, max);
	else if (a->top->next->value == min)
		input_three_middle_min_a(a, max);
	else if (a->top->next->next->value == min)
		input_three_bottom_min_a(a, max);
}
