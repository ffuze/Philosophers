/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:51:54 by adegl-in          #+#    #+#             */
/*   Updated: 2025/08/10 20:27:40 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*monitor_routine(void *arg)
{
	t_philo	**philos;
	int		i;

	philos = (t_philo **)arg;
	while (1)
	{
		i = -1;
		while (++i < philos[0]->table->n_philo)
		{
			if (is_dead(philos[i]) == 1)
				return (NULL);
		}
		if (f_eat(philos) == 1)
			return (NULL);
		usleep(500);
	}
	return (NULL);
}
