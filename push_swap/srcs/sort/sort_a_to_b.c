/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimhwang <gimhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:04:03 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 01:36:55 by gimhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_stop_recursion(int r, t_stack *a, t_stack *b)
{
	if (r <= 3)
	{
		control_under_three(r, a, b, A);
		return (1);
	}
	else if (r == 5)
	{
		control_sort_five(5, a, b, A);
		return (1);
	}
	else
		return (0);
}

static void	move_rotate_a(t_stack *a, t_stack *b, t_value *var)
{
	if (a->top->value > var->big_piv)
	{
		rotate_stack(a, A);
		var->ra++;
	}
	else
	{
		move_stack(a, b, B);
		var->pb++;
		if (b->top->value > var->small_piv)
		{
			rotate_stack(b, B);
			var->rb++;
		}
	}
}

static void	comeback_ra(t_stack *a, t_stack *b, int *cnt, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->rb;
	rem = var->ra - rrr;
	if ((*cnt) > 0)
	{
		while (rrr--)
			reverse_rotate_all_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(a, A);
	}
	else
	{
		while (rrr--)
			reverse_rotate_stack(b, B);
	}
}

static void	comeback_rb(t_stack *a, t_stack *b, int *cnt, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->ra;
	rem = var->rb - rrr;
	if ((*cnt) > 0)
	{
		while (rrr--)
			reverse_rotate_all_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(b, B);
	}
	else
	{
		rrr = var->rb;
		while (rrr--)
			reverse_rotate_stack(b, B);
	}
}

void	a_to_b(int size, t_stack *a, t_stack *b, int *cnt)
{
	int		temp_size;
	t_value	var;

	if (is_stop_recursion(size, a, b))
		return ;
	setting_pivot(size, a, &var);
	temp_size = size;
	while (temp_size--)
		move_rotate_a(a, b, &var);
	if (var.ra > var.rb)
		comeback_ra(a, b, cnt, &var);
	else
		comeback_rb(a, b, cnt, &var);
	a_to_b(var.ra, a, b, cnt);
	b_to_a(var.rb, a, b, cnt);
	b_to_a(var.pb - var.rb, a, b, cnt);
}
