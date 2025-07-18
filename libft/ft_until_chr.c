/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_until_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:46:10 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory and return a duplicate of the string s up until the first
//  occurrence of c
char	*ft_until_chr(const char *s, int c)
{
	char	*nstr;
	char	chr;
	int		i;
	int		j;

	chr = (char)c;
	i = 0;
	j = 0;
	while (s[i] && s[i] != chr)
		i++;
	nstr = ft_calloc(i + 2, sizeof(char));
	if (!nstr)
		return (NULL);
	while (j <= i)
	{
		nstr[j] = s[j];
		j++;
	}
	return (nstr);
}

// Allocates memory and return a duplicate of the string s up until right
//  before the first occurrence of c
char	*ft_before_chr(const char *s, int c)
{
	char	*nstr;
	char	chr;
	int		i;
	int		j;

	chr = (char)c;
	i = 0;
	j = 0;
	while (s[i] && s[i] != chr)
		i++;
	nstr = ft_calloc(i + 2, sizeof(char));
	if (!nstr)
		return (NULL);
	while (j < i)
	{
		nstr[j] = s[j];
		j++;
	}
	return (nstr);
}

//Prints the string s until the first occurrence of the character c
void	ft_until_chr_print(const char *s, int c)
{
	char	chr;
	int		i;

	chr = (char)c;
	i = 0;
	while (s[i])
	{
		ft_printf("%c", s[i]);
		if (s[i] == chr)
			break ;
		i++;
	}
}
