/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:17:54 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handleformat(const char *format, int *i, va_list args)
{
	unsigned long	n;
	int				uppercase;
	int				count;

	count = 0;
	if (format[*i + 1] == 'c')
		count += ft_printf_c((char)va_arg(args, int));
	else if (format[*i + 1] == 's')
		count += ft_printf_s((char *)va_arg(args, char *));
	else if (format[*i + 1] == 'p')
		count += ft_printf_p((void *)va_arg(args, void *));
	else if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
		count += ft_printf_d_i(va_arg(args, int));
	else if (format[*i + 1] == 'u')
		count += ft_printf_u(va_arg(args, unsigned int));
	else if (format[*i + 1] == 'x' || format[*i + 1] == 'X')
	{
		n = va_arg(args, unsigned long);
		uppercase = (format[*i + 1] == 'X');
		count += ft_printf_xl_xu(n, uppercase);
	}
	else if (format[*i + 1] == '%')
		count += ft_printf_c('%');
	(*i)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_handleformat(format, &i, args);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// int main(void)
// {
	// int i;
	// int j;
	// char *x = "mamaguevo gluglugluglu";
	// i = printf(" NULL %s NULL ", NULL);
	// j = ft_printf(" NULL %s NULL ", NULL);

	// printf("contatore printf normale %d", i);
	// printf("contatore printf ft %d", j);

	// printf("(ORIGINAL) String: %s\n", "Hello, world!");
	// ft_printf("(FT) String: %s\n\n", "Hello, world!");

	// i = printf("O: %x\n", 45201);
	// j = ft_printf("F: %x\n", 45201);
	// printf("contatore printf originale %d\n", i);
	// printf("contatore printf ft %d\n", j);

	// i = printf(" %d ", INT_MIN);
	// j = ft_printf(" %d ", INT_MIN);
	// printf("contatore printf originale %d\n", i);
	// printf("contatore printf ft %d\n", j);

	// printf("(ORIGINAL) Integer: %i\n", -5678);
	// ft_printf("(FT) Integer: %i\n\n", -5678);

	// printf("(ORIGINAL) Unsigned: %u\n", 429496);
	// ft_printf("(FT) Unsigned: %u\n\n", 429496);

	// i = printf(" %x ", LONG_MAX);
	// j = ft_printf(" %x ", LONG_MAX);
	// printf("valore di i: %d", i);
	// ft_printf("valore di j: %d", j);

	// i = printf(" %X ", 92233720368547);
	// j = ft_printf(" %X ", 92233720368547);
	// printf("valore di i: %d", i);
	// printf("valore di j: %d", j);

	// printf("(ORIGINAL) Double percent sign: %%\n");
	// ft_printf("(FT) Double percent sign: %%\n\n");

	// return 0;
// }
