/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:53:04 by hwankim           #+#    #+#             */
/*   Updated: 2022/12/09 15:59:05 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	ft_is_percent(const char	*str)//고정인자를 인자로 받아서  %기호 있는지 확인하는 그리고 그  다음 인덱스에 어떤 서식지정자가 있는지 확인하는 함수
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
	va_list	ap;//va_list는 가변인자(...)의 목록인 데이터 타입이다

	len = 0;
	i = 0;
	va_start(ap, str);//가변인자 시작주소 참조하기
	while (!(str[i] == '\0'))
	{
		if (ft_is_percent(&str[i]))//고정인자의 첫 문자가 %로 시작하고 그 다음에 인덱스가 서식지정자에서 정의하고 있는 타입중 하나 이면 1반환
		{
			len += ft_is_specifi(str[++i], ap);//해당 서식지정자에 맞는 함수로 가변인자를 보냄 그리고 가변인자의 길이를 len으로 반환
			++i;
		}
		else
		{
			len += write(1, &str[i], 1);
			++i;
		}
	}
	va_end(ap);//가변인자를 가르키는 포인터를 NULL로 초기화
	return (len);//가변인자 길이반환
}
