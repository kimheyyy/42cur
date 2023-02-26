/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:07:42 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/07 14:08:03 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define A 1
# define B 2
# define ALL 3

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack	t_stack;
typedef struct s_node	t_node;
typedef struct s_value	t_value;

struct	s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
};

struct	s_node
{
	int		value;
	t_node	*prev;
	t_node	*next;
};

struct	s_value
{
	long	big_piv;
	long	small_piv;
	int		ra;
	int		rb;
	int		pa;
	int		pb;
};

#endif
