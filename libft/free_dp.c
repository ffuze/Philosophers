/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:34:40 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/14 15:29:32 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Frees a char matrix
void	**free_dpc(char **double_pointer_char)
{
	int	i;

	i = 0;
	while (double_pointer_char[i])
	{
		free(double_pointer_char[i]);
		i++;
	}
	free(double_pointer_char);
	return (NULL);
}

// Frees an int matrix
void	**free_dpi(int **double_pointer_int)
{
	unsigned int	i;

	i = 0;
	while (i < (sizeof(double_pointer_int) / sizeof(double_pointer_int[0])))
	{
		free(double_pointer_int[i]);
		i++;
	}
	free(double_pointer_int);
	return (NULL);
}
