/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:08:18 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/08 18:49:02 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "structs.h"
# include "get_next_line_bonus.h"
# include "libft.h"

void	checker(t_stack *a, t_stack *b);

t_stack	*init_stack(void);
t_node	*make_stack(int argc, char **argv, t_stack **stack);

void	print_error(void);
int		check_input(char *arg);
void	check_same_input(t_node *a);
int		ft_atoi(char *arg);

void	swap_stack(t_stack *stack, int flag);
void	swap_all_stack(t_stack *a, t_stack *b, int flag);
void	move_stack(t_stack *from, t_stack *to, int flag);
void	rotate_stack(t_stack *stack, int flag);
void	rotate_all_stack(t_stack *a, t_stack *b, int flag);
void	reverse_rotate_stack(t_stack *stack, int flag);
void	reverse_rotate_all_stack(t_stack *a, t_stack *b, int flag);

void	do_push(char *buf, t_stack *a, t_stack *b);
void	do_swap(char *buf, t_stack *a, t_stack *b);
void	do_rotate(char *buf, t_stack *a, t_stack *b);
void	do_reverse_rotate(char *buf, t_stack *a, t_stack *b);

void	free_all(t_stack *a, t_stack *b);

#endif
