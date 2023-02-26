/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:08:26 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/07 14:08:55 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# ifndef LINE_BUFFER_SIZE
#  define LINE_BUFFER_SIZE 128
# endif

typedef struct s_buffer
{
	char	*buf;
	size_t	idx;
	size_t	size;
}	t_buffer;

typedef t_buffer	t_line_buffer;
typedef t_buffer	t_read_buffer;

char	*get_next_line(int fd);

#endif