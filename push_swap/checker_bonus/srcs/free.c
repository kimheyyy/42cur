/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:12:06 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/07 14:27:10 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	free_a(t_stack *a)
{
	t_node	*node;
	t_node	*temp;

	node = a->top;
	while (node)
	{
		if (node->next)
			temp = node->next;
		else
			temp = NULL;
		free(node);
		if (temp)
			node = temp;
		else
			break ;
	}
	free(a);
}

static void	free_b(t_stack *b)
{
	t_node	*node;
	t_node	*temp;

	node = b->top;
	while (node)
	{
		if (node->next)
			temp = node->next;
		else
			temp = NULL;
		free(node);
		if (temp)
			node = temp;
		else
			break ;
	}
	free(b);
}

void	free_all(t_stack *a, t_stack *b)
{
	free_a(a);
	free_b(b);
}
