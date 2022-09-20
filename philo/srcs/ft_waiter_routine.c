/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waiter_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:54:26 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/20 23:33:02 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_check_if_finished(t_prgrm *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < vars->nbr_of_philosophers)
	{
		pthread_mutex_lock(&vars->philos[j].meals_to_eat_mutex);
		while (vars->meals_to_eat[i])
		{
			if (vars->meals_to_eat[i] != 0)
			{
				pthread_mutex_unlock(&vars->philos[j].meals_to_eat_mutex);
				return (1);
			}
			i++;
		}
		pthread_mutex_unlock(&vars->philos[j].meals_to_eat_mutex);
		j++;
	}
	return (0);
}

void	*ft_waiter_routine(void *args)
{
	t_prgrm	*vars;
	int		i;
	int		j;

	vars = (t_prgrm *)args;
	i = 0;
	while (1)
	{
		if (ft_check_if_finished(vars) == 0)
			return (NULL);
		pthread_mutex_lock(&vars->philos[i].last_meal_mutex);
		if ((ft_get_time() - vars->philos[i].last_meal) >= vars->time_to_die)
		{
			j = 0;
			while (j < vars->nbr_of_philosophers)
			{
				pthread_mutex_lock(&vars->philos[j].philo_died_mutex);
				vars->philos[j].philo_died = 1;
				pthread_mutex_unlock(&vars->philos[j].philo_died_mutex);
				j++;
			}
			usleep(1000);
			pthread_mutex_lock(&vars->printf_mutex);
			printf("%ld: %d died.\n", ft_get_time() - vars->start_time, i + 1);
			pthread_mutex_unlock(&vars->printf_mutex);
			pthread_mutex_unlock(&vars->philos[i].last_meal_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&vars->philos[i].last_meal_mutex);
		if (i < vars->nbr_of_philosophers - 1)
			i++;
		else
			i = 0;
	}
	return (NULL);
}
