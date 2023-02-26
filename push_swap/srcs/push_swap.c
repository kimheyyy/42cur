/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:03:26 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 20:42:52 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(1);
}

void	init_value(t_value *var)
{
	var->ra = 0;
	var->rb = 0;
	var->pa = 0;
	var->pb = 0;
}

void	setting_pivot(int r, t_stack *stack, t_value *var)
{
	long	min;
	long	max;

	init_value(var);
	min = get_min_value(stack->top, r);
	max = get_max_value(stack->top, r);
	var->big_piv = (min + max) / 2;
	var->small_piv = (min + var->big_piv) / 2;
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	cnt;

	cnt = 0;
	if (a->size == 5)
		sort_input_five(a, b);
	else
		a_to_b(a->size, a, b, &cnt);
}
