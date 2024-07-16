/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:57:26 by yoaoki            #+#    #+#             */
/*   Updated: 2024/07/16 12:14:42 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_string(char * str, int *len)
{
	if (str == NULL)
		str = "(null)";
	while (*str)
		*len = write(1, str++, 1);
}

void	put_digit(long long int num, int base, int *len)
{
	char *hex = "0123456789abcdef";

	if (num < 0)
	{
		*len += write(1, "-", 1);
		num = -num;
	}
	if (num >= base)
		put_digit((num / base), base, len);
	*len += write(1, &hex[num % base], 1);
}

int	ft_printf(const char *fmt, ...)
{
	int len;
	int err;
	va_list ptr;
	
	len = 0;
	va_start(ptr, fmt);
	// if fmt == null -> segv
	while(*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			// maybe segv
			if (*fmt == 's')
				put_string(va_arg(ptr, char *), &len);
			if (*fmt == 'd')
				put_digit((long long int)va_arg(ptr, int), 10, &len);
			if (*fmt == 'x')
				put_digit((long long int)va_arg(ptr, unsigned int), 16, &len);
			fmt++;
		}
		else
			len += write(1, fmt++, 1);
	}
	return (va_end(ptr), len);
}
