/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:59:41 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*char	f(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (ft_toupper(c));
	else
		return (ft_tolower(c));
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptrs;

	if (!s || !f)
		return (NULL);
	i = 0;
	ptrs = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ptrs)
		return (NULL);
	while (s[i])
	{
		ptrs[i] = f(i, s[i]);
		i++;
	}
	ptrs[i] = '\0';
	return (ptrs);
}

/*int main()
{
	const char *str = "ciccio";
	char *papi = ft_strmapi(str, f);
	printf("Strmapi: %s", papi);
	free(papi);
}*/
