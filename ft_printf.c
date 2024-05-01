/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 02:53:18 by yoaoki            #+#    #+#             */
/*   Updated: 2024/05/02 00:12:39 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "include/ft_printf.h"

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(void); //??/
int	ft_putnbr(int num);
int	ft_putunbr(unsigned long long num);
int	ft_putnbr_lower_hex(int num);
int	ft_putnbr_upper_hex(int num);

int	ft_printf(const char *format, ...)
{
	int		result;
	char	*str;
	va_list	ap;

	va_start(ap, s);
	str = (char *)format;
	if (!str)
		return (0);
	result = 0;
	while (*str)
	{
		if (*str == '%')
			result += ft_put_conv(str, &ap);
		else
			result += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (result);
}

int	ft_put_conv(const char *s, va_list ap)
{
	str++;
	if (*str == 'c')
		return (ft_print_char(ap));
	if (*str == 's')
		return (ft_print_str(ap));
	if (*str == 'p')
		return (ft_print_ptr(ap));
	if (*str == 'd')
		return (ft_print_dec(ap));
	if (*str == 'i')
		return (ft_print_int(ap));
	if (*str == 'u')
		return (ft_print_uint(ap));
	if (*str == 'x')
		return (ft_print_hex_low(ap));
	if (*str == 'X')
		return (ft_print_hex_up(ap));
	if (*str == '%')
		return (ft_print_percent());
	return (0);
}

#include <stdio.h>
int	main(void)
{
	//void	foo(char *fmt,...);
	//foo("sdc", "Hello World", 123, 'A');
	char str[] = "Hello, World";
	char c = 'X';
	ft_printf("str: %s\nchar: %c\n", str, c); 
	return (0);
}

/*
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(void); //??/
int	ft_putnbr(int num);
int	ft_putunbr(unsigned long long num);
int	ft_putnbr_lower_hex(int num);
int	ft_putnbr_upper_hex(int num);
*/
int	ft_putchar(char c)
{
	write(1, &c, 1);
	// if write's retun value == -1 return (0)?
	return (1);
}

int ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_putstr(char *str)
{
	int n;

	n = ft_strlen(str);
	write(1, str, n);
	// if wirte's return value == -1 return (0)?
	return (n);
}






