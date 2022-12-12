/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:54:05 by hwankim           #+#    #+#             */
/*   Updated: 2022/12/07 12:34:44 by hwankim          ###   ########.fr       */
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
	int		s;

	c = n + 48;
	s = write(1, &c, 1);
	if (s == -1)
		return (-1);
	return (1);
}

int	ft_putnbr(long long n)
{
	int	len;
	int	s;

	len = 0;
	if (n < 0)
	{
		s = write(1, "-", 1);
		if (s == -1)
			return (-1);
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
	int	len;
	int	s;
	int	b;

	len = 0;
	if (nbr < 16)
	{
		s = write(1, &base[nbr], 1);
		if (s == -1)
			return (-1);
	}
	else
	{
		len += ft_hex_print(nbr / 16, base);
		b = write(1, &base[nbr % 16], 1);
		if (b == -1)
			return (-1);
	}
	len++;
	return (len);
}
