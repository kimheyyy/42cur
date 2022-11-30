/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:15:46 by hwankim          #+#    #+#             */
/*   Updated: 2022/11/21 14:48:24 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n);
void	free_buffer(t_buffer *prb);

static char	*exalloc_line_buffer(t_line_buffer	*plb)
{
	char	*new_buf;
	size_t	new_size;

	new_size = plb->size + 1;
	new_buf = malloc(sizeof(char) * (new_size + 1));
	if (new_buf != NULL && plb->buf != NULL)
		ft_memcpy(new_buf, plb->buf, plb->size);
	free(plb->buf);
	if (new_buf == NULL)
		return (NULL);
	plb->buf = new_buf;
	plb->size = new_size;
	return (new_buf);
}

static char	*alloc_read_buffer(t_read_buffer *prb)
{
	if (prb->buf == NULL)
	{
		prb->buf = malloc(sizeof(char) * BUFFER_SIZE);
		if (prb->buf == NULL)
			return (NULL);
		prb->idx = 0;
		prb->size = 0;
	}
	return (prb->buf);
}

static int	read_from_file(int fd, t_read_buffer *prb)
{
	ssize_t	new_size;

	if (prb->idx >= prb->size)
	{
		new_size = read(fd, prb->buf, BUFFER_SIZE);
		if (new_size == 0)
			return ('\0');
		else if (new_size == -1)
			return (-1);
		prb->idx = 0;
		prb->size = new_size;
	}
	return (prb->buf[prb->idx++]);
}

static int	read_to_line(t_line_buffer *plb, char ch)
{
	if (plb->idx >= plb->size)
	{
		if (exalloc_line_buffer(plb) == NULL)
			return (0);
	}
	plb->buf[plb->idx++] = ch;
	if (ch == '\n')
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	int									ch;
	t_line_buffer						lb;
	static t_read_buffer				rb;

	if (alloc_read_buffer(&rb) == NULL)
		return (NULL);
	lb.buf = NULL;
	lb.idx = 0;
	lb.size = 0;
	ch = '\0';
	while (ch != -1)
	{
		ch = read_from_file(fd, &rb);
		if (ch == -1)
			free_buffer(&lb);
		else if (ch == '\0' || read_to_line(&lb, ch) == 0)
			break ;
	}
	if (lb.idx == 0)
		free_buffer(&rb);
	else
		lb.buf[lb.idx] = '\0';
	return (lb.buf);
}
