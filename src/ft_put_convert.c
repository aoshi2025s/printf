/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:22:54 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/02 03:09:31 by yoaoki           ###   ########.fr       */
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
		return (0);
	if (*str == 'd')
		return (0);
	if (*str == 'i')
		return (0);
	if (*str == 'u')
		return (0);
	if (*str == 'x')
		return (0);
	if (*str == 'X')
		return (0);
	if (*str == '%')
		return (ft_print_percent());
	return (0);
}
