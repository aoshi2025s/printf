/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:22:54 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/02 02:35:04 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_convert(const char *str, va_list *ap)
{
	str++;
	if (*str == 'c')
		return (ft_print_char(ap));
	if (*str == 's')
		return (ft_print_str(ap));
	if (*str == 'p')
		return (0);//ft_print_ptr(ap));
	if (*str == 'd')
		return (0);//ft_print_dec(ap));
	if (*str == 'i')
		return (0);//ft_print_int(ap));
	if (*str == 'u')
		return (0);//ft_print_uint(ap));
	if (*str == 'x')
		return (0);//ft_print_hex_low(ap));
	if (*str == 'X')
		return (0);//ft_print_hex_up(ap));
	if (*str == '%')
		return (ft_print_percent());
	return (0);
}
