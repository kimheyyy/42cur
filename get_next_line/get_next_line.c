/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimhwang <gimhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:15:46 by gimhwang          #+#    #+#             */
/*   Updated: 2022/11/20 11:11:24 by gimhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n);
void	free_read_buffer(t_read_buffer *prb);

static char	*exalloc_line_buffer(t_line_buffer	*plb)//line_buff크기 확장 시켜줌
{
	char	*new_buf;
	size_t	new_size;

	new_size = plb->size + LINE_BUFFER_SIZE;
	new_buf = malloc(sizeof(char) * (new_size + 1));
	if (plb->buf != NULL)
	{
		if (new_buf != NULL)
			ft_memcpy(new_buf, plb->buf, plb->size);
		free(plb->buf);
	}
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
		prb->idx = 0;//초기화
		prb->size = 0;//초기화
	}
	return (prb->buf);//할당성공한거 반환
}

static int	read_from_file(int fd, t_read_buffer *prb)
{
	if (prb->idx >= prb->size)//처음에 한번 실행 된 후 idx가 size크기에 해당하는 값을 가질때 다시 실행 됨(read로 읽어온 문자열중에서 개행이 없고 line에 다 옮겼을때)
	{
		prb->size = read(fd, prb->buf, BUFFER_SIZE);
		if (prb->size < 1)
			return ('\0');
		prb->idx = 0;
	}
	return (prb->buf[prb->idx++]);//읽어온 문자하나씩 반환///idx가 size에 도달 할 때 까지,개행을 발견할떄까지
}

static int	read_to_line(t_line_buffer *plb, char ch)//ch는 read_from_file에서 반환 받은 값임..
{
	if (plb->idx >= plb->size)
	{
		if (exalloc_line_buffer(plb) == NULL)
			return (0);
	}
	plb->buf[plb->idx++] = ch;//read_from_file에서 반환받은 데이터를 line에 하나씩 넣는 작업
	if (ch == '\n')//개행이 있으면 함수 종료
		return (0);
	return (1);//line에 개행 넣지 않았으면 1 반환
}

char	*get_next_line(int fd)
{
	int	ch;
	t_line_buffer	lb;//read로 읽어온 데이터를 받을 변수
	static t_read_buffer	rb[OPEN_MAX] = {{NULL, 0, 0}};//반환했던 문자의 주소+1을 가지도록 설계..백업버퍼

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (alloc_read_buffer(&rb[fd]) == NULL)//read_buffer의 동적할당을 실패했을때 
		return (NULL);
	lb.buf = NULL;
	lb.idx = 0;
	lb.size = 0;
	while (1)
	{
		ch = read_from_file(fd, &rb[fd]);
		if (ch == '\0')//파일로부터 문자열널값이 들어오거나
			break ;
		if (read_to_line(&lb, ch) == 0)//개행을 넣지 않았으면 1이 반환되므로//0이 반환되면  개행을 발견
			break ;
            //반복문은 계속해서 돈다
	}
	if (lb.idx == 0)
		free_read_buffer(&rb[fd]);
	else
		lb.buf[lb.idx] = '\0';//line_buffer의 끝에 널 값을 넣어줌
	return (lb.buf);
}