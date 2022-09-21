/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:51:34 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/21 10:51:10 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

// I add the seconds * 1000 to the microseconds / 1000 to get one big number 
// containing the miliseconds of the moment of start.

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)(tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_join_threads(t_prgrm *vars)
{
	int	i;

	i = 0;
	while (i < vars->nbr_of_philosophers)
	{
		if (pthread_join(vars->philos[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_free_structs(t_prgrm *vars)
{
	int	i;

	i = 0;
	while (i < vars->nbr_of_philosophers)
	{
		pthread_mutex_destroy(&vars->philos[i].philo_died_mutex);
		pthread_mutex_destroy(&vars->philos[i].last_meal_mutex);
		pthread_mutex_destroy(&vars->forks[i].mutex);
		i++;
	}
	free(vars->meals_to_eat);
	free(vars->philos);
	free(vars->forks);
	pthread_mutex_destroy(&vars->printf_mutex);
	pthread_mutex_destroy(&vars->philo_died_mutex);
	return (0);
}

int	ft_check_if_dead(t_philos *philosopher)
{
	pthread_mutex_lock(&philosopher->philo_died_mutex);
	if (philosopher->philo_died == 1)
	{
		pthread_mutex_unlock(&philosopher->philo_died_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philosopher->philo_died_mutex);
	return (0);
}
