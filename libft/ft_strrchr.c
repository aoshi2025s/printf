/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:31:34 by yoaoki            #+#    #+#             */
/*   Updated: 2024/04/18 23:08:46 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*curr;
	char	target;
	int		len;

	curr = (char *)str;
	target = (char)c;
	len = 0;
	while (*curr)
	{
		curr++;
		len++;
	}
	if (target == '\0')
		return (curr);
	curr--;
	while (len)
	{
		if (*curr == target)
			return (curr);
		curr--;
		len--;
	}
	return (0);
}
