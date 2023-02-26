/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimhwang <gimhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:04:26 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 01:36:59 by gimhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_stop_recursion(int r, t_stack *a, t_stack *b)
{
	if (r <= 3)
	{
		control_under_three(r, a, b, B);
		return (0);
	}
	else if (r == 5)
	{
		control_sort_five(5, a, b, B);
		return (0);
	}
	else
		return (1);
}

static void	move_rotate_b(t_stack *a, t_stack *b, t_value *var)
{
	if (b->top->value <= var->small_piv)
	{
		rotate_stack(b, B);
		var->rb++;
	}
	else
	{
		move_stack(b, a, A);
		var->pa++;
		if (a->top->value <= var->big_piv)
		{
			rotate_stack(a, A);
			var->ra++;
		}
	}
}

static void	comeback_ra(t_stack *a, t_stack *b, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->rb;
	rem = var->ra - rrr;
	while (rrr--)
		reverse_rotate_all_stack(a, b, ALL);
	while (rem--)
		reverse_rotate_stack(a, A);
}

static void	comeback_rb(t_stack *a, t_stack *b, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->ra;
	rem = var->rb - rrr;
	while (rrr--)
		reverse_rotate_all_stack(a, b, ALL);
	while (rem--)
		reverse_rotate_stack(b, B);
}

void	b_to_a(int r, t_stack *a, t_stack *b, int *cnt)
{
	int		r_temp;
	t_value	var;

	(*cnt)++;
	if (!is_stop_recursion(r, a, b))
		return ;
	init_value(&var);
	setting_pivot(r, b, &var);
	r_temp = r;
	while (r_temp--)
		move_rotate_b(a, b, &var);
	a_to_b(var.pa - var.ra, a, b, cnt);
	if (var.ra > var.rb)
		comeback_ra(a, b, &var);
	else
		comeback_rb(a, b, &var);
	a_to_b(var.ra, a, b, cnt);
	b_to_a(var.rb, a, b, cnt);
}
