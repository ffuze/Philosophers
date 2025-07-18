/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:48:37 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_c(int c)
{
	int	i;

	i = 1;
	write(1, &c, 1);
	return (i);
}

int	ft_printf_s(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf_p(void *p)
{
	char			*base;
	int				i;
	char			res[17];
	unsigned long	pvalue;
	int				count;

	count = 2;
	i = 0;
	pvalue = (unsigned long)p;
	base = "0123456789abcdef";
	if (!p)
		return (write(1, "(nil)", 5));
	while (pvalue > 0)
	{
		res[i++] = base[pvalue % 16];
		pvalue /= 16;
	}
	write(1, "0x", 2);
	while (i > 0)
	{
		write(1, &res[--i], 1);
		count++;
	}
	return (count);
}
