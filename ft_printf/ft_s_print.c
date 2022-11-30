/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:53:43 by hwankim           #+#    #+#             */
/*   Updated: 2022/11/29 23:31:16 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s_print(va_list ap)
{
	char	*tmp;

	tmp = va_arg(ap, char *);
	if (!tmp)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, tmp, ft_strlen(tmp));
	return (ft_strlen(tmp));
}
