/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:11:09 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 20:27:36 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	is_sorted(t_stack *a)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->next)
		{
			if (node->value > node->next->value)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->value == a->bottom->value)
		return (1);
	else
		return (0);
}

void	check_operations(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("pa", buf) || !ft_strcmp("pb", buf))
		do_push(buf, a, b);
	else if (!ft_strcmp("sa", buf) || !ft_strcmp("sb", buf) || \
	!ft_strcmp("ss", buf))
		do_swap(buf, a, b);
	else if (!ft_strcmp("ra", buf) || !ft_strcmp("rb", buf) || \
	!ft_strcmp("rr", buf))
		do_rotate(buf, a, b);
	else if (!ft_strcmp("rra", buf) || !ft_strcmp("rrb", buf) || \
	!ft_strcmp("rrr", buf))
		do_reverse_rotate(buf, a, b);
	else
		print_error();
}

void	checker(t_stack *a, t_stack *b)
{
	char	*buf;

	buf = get_next_line(0);
	while (buf)
	{
		check_operations(buf, a, b);
		free(buf);
		buf = get_next_line(0);
	}
	free(buf);
	if (is_sorted(a) && !b->top)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
