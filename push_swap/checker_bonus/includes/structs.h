/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:09:05 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/07 14:09:15 by hwankim          ###   ########.fr       */
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

#endif
