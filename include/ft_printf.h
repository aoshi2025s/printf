/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 02:42:02 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/03 14:10:50 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);

int	ft_put_convert(const char *str, va_list *ap);
int	ft_print_char(va_list *ap);
int	ft_print_str(va_list *ap);
// int	ft_print_ptr(va_list *ap);
// int	ft_print_nbr(va_list *ap);
int	ft_print_int(va_list *ap);
int	ft_print_uint(va_list *ap);
// int	ft_print_hex_low(va_list *ap);
// int	ft_print_hex_up(va_list *ap);
int	ft_print_percent(void);

//utils
int	ft_numlen(long long n);
void	ft_putuint_fd(unsigned int n);
#endif
