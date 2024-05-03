/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:05:22 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/03 23:17:18 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_fd(unsigned int num, int fd)
{
	if (num < 16)
	{
		ft_putchar_fd(BASE[num % 16], fd);
	}
	if (num >= 16)
	{
		ft_puthex_fd(num / 16, fd);
		ft_putchar_fd(BASE[num % 16], fd);
	}
}
