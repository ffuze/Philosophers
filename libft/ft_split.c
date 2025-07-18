/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:38:22 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	free_matrix(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		if (array[i])
		{
			free(array[i]);
			array[i] = NULL;
		}
		i++;
	}
	free(array);
}

static int	words(const char *str, char delim)
{
	size_t	n;
	int		beg;

	n = 0;
	beg = 0;
	while (*str)
	{
		if (*str != delim && beg == 0)
		{
			beg = 1;
			n++;
		}
		else if (*str == delim)
			beg = 0;
		str++;
	}
	return (n);
}

static char	*duping(const char *s, int start, int end)
{
	char	*ptrs;
	int		i;

	i = 0;
	if (start < 0 || end <= start)
		return (NULL);
	ptrs = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ptrs)
	{
		return (NULL);
	}
	while (start < end)
		ptrs[i++] = s[start++];
	ptrs[i] = '\0';
	return (ptrs);
}

static char	**fill_split(char const *s, char c, char **res, int start)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			res[index] = duping(s, start, i);
			if (!res[index])
			{
				free_matrix(res);
				return (NULL);
			}
			index++;
		}
		if (s[i] == c && s[i])
			i++;
	}
	res[index] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		start;

	start = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (words(s, c) + 1));
	if (!res)
		return (NULL);
	return (fill_split(s, c, res, start));
}

/* int main()
{
    char str[] = "nonempty";
    char delimiter = 'n';
    char **result = ft_split(str, delimiter);
    unsigned int i = 0;
    if (!result)
        return (1);
    while (result[i])
    {
        printf("Substring %d: %s\n", i, result[i]);
		i++;
    }
	printf("%s", result[i]);
	free_matrix(result);
    return (0);
} */
