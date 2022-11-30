/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:53:36 by hwankim           #+#    #+#             */
/*   Updated: 2022/11/29 23:38:11 by hwankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_strlen(const char	*str);
int		ft_putnbr(long long n);
int		ft_hex_print(unsigned long long nbr, char *base);
int		ft_c_print(va_list ap);
int		ft_s_print(va_list ap);
int		ft_p_print(va_list ap);
int		ft_di_print(va_list ap);
int		ft_u_print(va_list ap);
int		ft_xx_print(int c, va_list ap);
int		ft_printf(const char *str, ...);

#endif