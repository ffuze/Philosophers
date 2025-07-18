/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:27:05 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;
	int		tot;

	tot = nmemb * size;
	i = 0;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (tot / size != nmemb)
		return (NULL);
	ptr = malloc(tot);
	if (ptr == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

/*int main()
{
	size_t	n = 5;
	int *arr = ft_calloc(n, sizeof(int));
	if (!arr)
		printf("Non e' stato allocato niente in memoria");
	else
	{
		size_t i = 0;
		while (i < n)
		{
			printf("arr[%ld] = %d\n", i, arr[i]);
			i++;
			
		}
	}
	free(arr);
}*/
