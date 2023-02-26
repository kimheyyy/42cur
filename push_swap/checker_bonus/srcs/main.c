/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:12:13 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 20:20:12 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		exit(0);
	if (argc > 1)
	{
		a = init_stack();
		b = init_stack();
		a->top = make_stack(argc, argv, &a);
		check_same_input(a->top);
		checker(a, b);
		free_all(a, b);
	}
	return (0);
}
