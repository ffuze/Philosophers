/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:16:33 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	size_t			slen;
	unsigned int	i;

	slen = ft_strlen(s);
	i = 0;
	if (start >= slen)
	{
		subs = ft_calloc(1, sizeof(char));
		if (!subs)
			return (NULL);
		return (subs);
	}
	if (ft_strlen(s) - start < len)
		len = slen - start;
	subs = ft_calloc(sizeof(char), len + 1);
	if (!subs)
		return (NULL);
	while (s[start + i] && i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

/*int	main()
{
	const char *s = "lorem ipsum dolor sit amet";
	char *sub = ft_substr(s, 0, 10);
	printf("%s", sub);
	free(sub);
}*/
