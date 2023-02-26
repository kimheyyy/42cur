/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimhwang <gimhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:06:06 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 01:37:35 by gimhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	from_size_one(t_stack *from, t_stack *to)
{
	if (to->size == 0)
	{
		to->top = from->top;
		to->bottom = to->top;
	}
	else
	{
		to->top->prev = from->top;
		from->top->next = to->top;
		to->top = to->top->prev;
	}
	from->top = NULL;
	from->bottom = NULL;
}

static void	push_pop(t_stack *from, t_stack *to)
{
	if (from->size == 1)
		from_size_one(from, to);
	else
	{
		if (to->size == 0)
		{
			to->top = from->top;
			to->bottom = to->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->next = NULL;
		}
		else
		{
			to->top->prev = from->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->prev->next = to->top;
			to->top = to->top->prev;
		}
	}
	to->size++;
	from->size--;
}

void	move_stack(t_stack *from, t_stack *to, int flag)
{
	if (from->size == 0)
		return ;
	push_pop(from, to);
	if (flag == A)
		ft_putendl_fd("pa", 1);
	else if (flag == B)
		ft_putendl_fd("pb", 1);
}
