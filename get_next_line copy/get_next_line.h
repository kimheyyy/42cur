/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:16:13 by hwankim           #+#    #+#             */
/*   Updated: 2022/11/20 18:18:12 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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