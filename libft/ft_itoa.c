/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:11:33 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	count_digits(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int					len;
	unsigned int		num;
	char				*result;

	len = count_digits(n);
	if (n < 0)
		num = -n;
	else
		num = n;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len--)
	{
		result[len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

// int main()
// {
// 	char *str;

// 	str = ft_itoa(42);
// 	printf("%s\n", str); // Output: "42"
// 	free(str);

// 	str = ft_itoa(+42);
// 	printf("%s\n", str); // Output: "-42"
// 	free(str);

// 	str = ft_itoa(0);
// 	printf("%s\n", str); // Output: "0"
// 	free(str);

// 	str = ft_itoa(-2147483648);
// 	printf("%s\n", str); // Output: "-2147483648"
// 	free(str);

// 	str = ft_itoa(-10);
// 	printf("%s\n", str);
// 	free(str);
// }
