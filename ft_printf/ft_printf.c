/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:53:04 by hwankim           #+#    #+#             */
/*   Updated: 2022/11/30 02:12:55 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	ft_is_percent(const char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '%' \
	&& (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'p' \
	|| str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u' \
	|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%'))
	{
		return (1);
	}
	return (0);
}

static int	ft_is_specifi(char c, va_list ap)
{
	if (c == 'c')
		return (ft_c_print(ap));
	else if (c == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	else if (c == 's')
		return (ft_s_print(ap));
	else if (c == 'p')
		return (ft_p_print(ap));
	else if (c == 'd' || c == 'i')
		return (ft_di_print(ap));
	else if (c == 'u')
		return (ft_u_print(ap));
	else if (c == 'x' || c == 'X')
		return (ft_xx_print(c, ap));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	ap;

	len = 0;
	i = 0;
	va_start(ap, str);
	while (!(str[i] == '\0'))//형식문자열에서 0번 인덱스 부터 조사
	{
		if (ft_is_percent(&str[i]))//형식문자열(고정인자)에서 %확인
		{
			len += ft_is_specifi(str[++i], ap);//서식 확인후 해당 함수호출
			++i;
		}
		else//%없으면 그냥 출력
		{
			len += write(1, &str[i], 1);
			++i;
		}
	}
	va_end(ap);
	return (len);
}
