/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 02:53:18 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/02 02:37:18 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		result;
	char	*str;
	va_list	ap;

	va_start(ap, format);
	str = (char *)format;
	if (!str)
		return (0);
	result = 0;
	while (*str)
	{
		if (*str == '%')
		{
			result += ft_put_convert(str, &ap);
			str++;
		}
		else
			result += ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(ap);
	return (result);
}
