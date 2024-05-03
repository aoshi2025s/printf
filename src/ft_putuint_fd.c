/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 01:31:21 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/03 14:18:43 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint_fd(unsigned int num)
{
	if (num < 10)
	{
		ft_putchar_fd(num % 10 + '0', 1);
	}
	if (num >= 10)
	{
		ft_putuint_fd(num / 10);
		ft_putchar_fd(num % 10 + '0', 1);
	}
}

// 12345
// ft_print_uint(12345) -> ft_putchar_fd('5', 1);
// ft_print_uint(1234) -> ft_putchar_fd('4', 1);
// ft_print_uint(123) -> ft_putchar_fd('3', 1);
// ft_print_uint(12) -> ft_putchar_fd('2', 1);
// ft_print_uint(1) -> ft_putchar_fd('1', 1);
