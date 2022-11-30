/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:54:05 by hwankim           #+#    #+#             */
/*   Updated: 2022/11/30 02:11:04 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_putchar(int n)
{
	char	c;

	c = n + 48;
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		len += ft_putnbr(n) + 1;
	}
	else if (n <= 9)
	{
		ft_putchar(n);
		len++;
	}
	else
	{
		len += ft_putnbr(n / 10);
		len += ft_putchar(n % 10);
	}
	return (len);
}

int	ft_hex_print(unsigned long long nbr, char *base)
{
	int		len;

	len = 0;
	if (nbr < 16)
		write(1, &base[nbr], 1);
	else
	{
		len += ft_hex_print(nbr / 16, base);
		write(1, &base[nbr % 16], 1);
	}
	len++;
	return (len);
}
