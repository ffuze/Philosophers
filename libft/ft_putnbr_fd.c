/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:25:38 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

/*int main()
{
	ft_putnbr_fd(42, 1);          // Stampa: 42
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-123, 1);        // Stampa: -123
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0, 1);           // Stampa: 0
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-2147483648, 1); // Stampa: -2147483648
	ft_putchar_fd('\n', 1);
	return 0;
}*/
