/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:09:43 by hwankim           #+#    #+#             */
/*   Updated: 2023/02/07 14:09:45 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			i;

	if (!dest && !src)
		return (0);
	new_dest = dest;
	new_src = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*new_dest++ = *new_src++;
	return (dest);
}

void	free_buffer(t_buffer *prb)
{
	if (prb->buf != NULL)
	{
		free(prb->buf);
		prb->buf = NULL;
	}
	prb->idx = 0;
	prb->size = 0;
}
