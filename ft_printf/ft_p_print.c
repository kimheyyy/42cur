/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:53:22 by hwankim           #+#    #+#             */
/*   Updated: 2022/11/29 23:27:05 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_p_print(va_list ap)
{
	unsigned long long	adr;

	adr = (unsigned long long)va_arg(ap, void *);
	write(1, "0x", 2);
	return (ft_hex_print(adr, "0123456789abcdef") + 2);
}
