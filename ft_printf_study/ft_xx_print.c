/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:53:53 by hwankim           #+#    #+#             */
/*   Updated: 2022/11/29 22:55:39 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_xx_print(int c, va_list ap)
{
	unsigned int	tmp;

	tmp = (unsigned int)va_arg(ap, int);
	if (c == 'x')
		return (ft_hex_print(tmp, "0123456789abcdef"));
	if (c == 'X')
		return (ft_hex_print(tmp, "0123456789ABCDEF"));
	return (0);
}
