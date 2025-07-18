/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:17:12 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_convert(int fd, va_list arg, const char format)
{
	int		printed;

	printed = 0;
	if (format == 'c')
		return (ft_putchar_fd(va_arg(arg, int), fd));
	else if (format == 's')
		return (ft_putstr_fd((va_arg(arg, char *)), fd));
	else if (format == 'd' || format == 'i')
		printed += fd_print_n(fd, va_arg(arg, int));
	else if (format == 'p')
		printed += fd_print_p(fd, va_arg(arg, intptr_t *));
	else if (format == 'x' || format == 'X')
		printed += fd_print_hex(fd, va_arg(arg, unsigned int), format);
	else if (format == 'u')
		printed += fd_print_u(fd, va_arg(arg, unsigned int));
	else if (format == '%')
		printed += ft_putchar_fd(37, fd);
	return (printed);
}

int	ft_printfd(int fd, const char *input, ...)
{
	int		i;
	int		printed;
	va_list	arg;

	i = 0;
	printed = 0;
	va_start(arg, input);
	if (!input)
		return (-1);
	while (input[i])
	{
		if (input[i] == '%')
		{
			printed += ft_convert(fd, arg, input[i + 1]);
			i++;
		}
		else
		{
			write(fd, &input[i], 1);
			printed ++;
		}
		i++;
	}
	va_end(arg);
	return (printed);
}
