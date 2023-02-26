/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimhwang <gimhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:04:37 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 01:37:03 by gimhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_five_a(int size, t_stack *a, t_stack *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = setting_value_to_list(a->top);
	while (size--)
	{
		if (a->top->value < mid)
		{
			move_stack(a, b, B);
			push++;
		}
		else
		{
			rotate_stack(a, A);
			rotate++;
		}
		if (push == 2)
			break ;
	}
	while (rotate--)
		reverse_rotate_stack(a, A);
}

static void	sort_five_b(int size, t_stack *a, t_stack *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = setting_value_to_list(b->top);
	while (size--)
	{
		if (b->top->value >= mid)
		{
			move_stack(b, a, A);
			push++;
		}
		else
		{
			rotate_stack(b, B);
			rotate++;
		}
		if (push == 3)
			break ;
	}
	while (rotate--)
		reverse_rotate_stack(b, B);
}

void	control_sort_five(int size, t_stack *a, t_stack *b, int flag)
{
	if (flag == A)
		sort_five_a(size, a, b);
	else
		sort_five_b(size, a, b);
	sort_input_three_a(3, a);
	sort_input_two(a, b, B);
}

void	sort_input_five(t_stack *a, t_stack *b)
{
	int	pb;
	int	mid;

	pb = 0;
	mid = setting_value_to_list(a->top);
	while (1)
	{
		if (a->top->value < mid)
		{
			move_stack(a, b, B);
			pb++;
		}
		else
			rotate_stack(a, A);
		if (pb == 2)
			break ;
	}
	sort_input_three_a(3, a);
	sort_input_two(a, b, B);
}
