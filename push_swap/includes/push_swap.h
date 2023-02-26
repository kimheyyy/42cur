/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:07:33 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 16:14:38 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "structs.h"

void	print_error(void);
int		check_input(char *arg);
int		ft_atoi(char *arg);
void	check_same_input(t_node *a);
t_stack	*init_stack(void);
t_node	*make_stack(int argc, char **argv, t_stack **stack);
void	init_value(t_value *var);
int		get_min_value(t_node *node, int size);
int		get_max_value(t_node *node, int size);
int		setting_value_to_list(t_node *node);

void	swap_stack(t_stack *stack, int flag);
void	swap_all_stack(t_stack *a, t_stack *b, int flag);
void	move_stack(t_stack *from, t_stack *to, int flag);
void	rotate_stack(t_stack *stack, int flag);
void	rotate_all_stack(t_stack *a, t_stack *b, int flag);
void	reverse_rotate_stack(t_stack *stack, int flag);
void	reverse_rotate_all_stack(t_stack *a, t_stack *b, int flag);

void	push_swap(t_stack *a, t_stack *b);
void	sort_input_three_a(int r, t_stack *a);
void	sort_input_three_b(int r, t_stack *a, t_stack *b);
void	control_under_three(int r, t_stack *a, t_stack *b, int flag);
void	sort_input_two(t_stack *a, t_stack *b, int flag);
void	sort_input_five(t_stack *a, t_stack *b);
void	control_sort_five(int size, t_stack *a, t_stack *b, int flag);
void	setting_pivot(int r, t_stack *stack, t_value *var);
void	a_to_b(int r, t_stack *a, t_stack *b, int *cnt);
void	b_to_a(int r, t_stack *a, t_stack *b, int *cnt);
void	free_all(t_stack *a, t_stack *b);

void	print_stack_a(t_stack *a);
void	print_stack_b(t_stack *b);

#endif
