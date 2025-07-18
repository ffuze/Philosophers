/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:25:36 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fd_putnbr_p(int fd, unsigned long nbr)
{
	int	l;

	l = 0;
	if (nbr >= 16)
	{
		l += fd_putnbr_p(fd, (nbr / 16));
		l += fd_putnbr_p(fd, (nbr % 16));
	}
	else
	{
		if (nbr <= 9)
			l += ft_putchar_fd((nbr + '0'), fd);
		else
			l += ft_putchar_fd((nbr - 10 + 'a'), fd);
	}
	return (l);
}

int	fd_print_p(int fd, intptr_t *p)
{
	int	l;

	l = 0;
	if (!p)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	write(fd, "0x", 2);
	l += 2;
	l += fd_putnbr_p(fd, (unsigned long)p);
	return (l);
}
