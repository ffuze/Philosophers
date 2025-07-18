/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:49:14 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_xl_xu(unsigned int n, int uppercase)
{
	char			*base;
	char			res[17];
	int				i;
	int				count;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		res[i++] = base[n % 16];
		n /= 16;
	}
	res[i] = '\0';
	count = i;
	while (--i >= 0)
		write(1, &res[i], 1);
	return (count);
}
