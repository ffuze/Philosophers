/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:50:12 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	ptrdest = (unsigned char *)(dest);
	ptrsrc = (unsigned char *)(src);
	i = 0;
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (ptrdest);
}

/*int main()
{
	char dest[] = "zyxwvutsrqponm";
	char src[] = "lkjihgfedcba";

	printf("Before memcpy(): %s\n", dest);

	// Copies contents of str2 to str1
	ft_memcpy(dest, src, sizeof(src));

	printf("After memcpy(): %s", dest);

	return 0;
}*/
