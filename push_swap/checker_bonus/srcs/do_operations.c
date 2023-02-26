/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimhwang <gimhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:11:57 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 01:38:35 by gimhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	do_push(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("pa", buf))
		move_stack(b, a, 0);
	else if (!ft_strcmp("pb", buf))
		move_stack(a, b, 0);
}

void	do_swap(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("sa", buf))
		swap_stack(a, 0);
	else if (!ft_strcmp("sb", buf))
		swap_stack(b, 0);
	else
		swap_all_stack(a, b, 0);
}

void	do_rotate(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("ra", buf))
		rotate_stack(a, 0);
	else if (!ft_strcmp("rb", buf))
		rotate_stack(b, 0);
	else
		rotate_all_stack(a, b, 0);
}

void	do_reverse_rotate(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("rra", buf))
		reverse_rotate_stack(a, 0);
	else if (!ft_strcmp("rrb", buf))
		reverse_rotate_stack(b, 0);
	else
		reverse_rotate_all_stack(a, b, 0);
}
