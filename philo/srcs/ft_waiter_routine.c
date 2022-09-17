/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waiter_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:54:26 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/17 22:28:39 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*ft_waiter_routine(void *args)
{
	t_prgrm	*vars;
	int		i;

	vars = (t_prgrm *)args;
	i = 0;
	while (1)
	{
		if ((int)(ft_get_time() - vars->philos[i].last_meal) >= vars->time_to_die)
		{
			pthread_mutex_lock(&vars->philo_died_mutex);
			vars->philo_died = 1;
			pthread_mutex_unlock(&vars->philo_died_mutex);
			pthread_mutex_lock(&vars->printf_mutex);
			printf("%ld: %d died.\n", ft_get_time() - vars->start_time, i);
			pthread_mutex_unlock(&vars->printf_mutex);
			return (NULL);
		}
		if (i < vars->nbr_of_philosophers - 1)
			i++;
		else
			i = 0;
	}
	return (NULL);
}
