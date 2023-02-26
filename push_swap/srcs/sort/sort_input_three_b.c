/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input_three_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimhwang <gimhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:05:02 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 01:37:13 by gimhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	input_three_top_min_b(t_stack *b, int max)
{
	if (b->size == 3)
	{
		rotate_stack(b, B);
		if (b->top->next->value == max)
			swap_stack(b, B);
	}
	else
	{
		swap_stack(b, B);
		rotate_stack(b, B);
		swap_stack(b, B);
		reverse_rotate_stack(b, B);
		if (b->top->next->value == max)
			swap_stack(b, B);
	}
}

void	input_three_middle_min_b(t_stack *b, int max)
{
	if (b->size == 3)
	{
		reverse_rotate_stack(b, B);
		if (b->top->next->value == max)
			swap_stack(b, B);
	}
	else
	{
		rotate_stack(b, B);
		swap_stack(b, B);
		reverse_rotate_stack(b, B);
		if (b->top->next->value == max)
			swap_stack(b, B);
	}
}

void	input_three_bottom_min_b(t_stack *b, int max)
{
	if (b->top->next->value == max)
		swap_stack(b, B);
}

void	sort_input_three_b(int r, t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = get_min_value(b->top, r);
	max = get_max_value(b->top, r);
	if (b->top->value == min)
		input_three_top_min_b(b, max);
	else if (b->top->next->value == min)
		input_three_middle_min_b(b, max);
	else if (b->top->next->next->value == min)
		input_three_bottom_min_b(b, max);
	move_stack(b, a, A);
	move_stack(b, a, A);
	move_stack(b, a, A);
}
