/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:09:11 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*void	f(unsigned int i, char *s)
{
	if (i % 2 == 1)
		*s = ft_toupper(*s);
	else
		*s = ft_tolower(*s);
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*int main()
{
	char str[] = "SKOTCHO sCaToLa bUsTa PACCHETTO";
	printf("Stringa prima del richiamo: %s\n", str);	
	ft_striteri(str, f);
	printf("Stringa dopo il richiamo: %s", str);
}*/
