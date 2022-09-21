/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_sleep_think.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:51:50 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/21 11:04:03 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_helper_2(t_philos *philosopher)
{
	if (ft_check_if_dead(philosopher) == 1)
	{
		ft_unlock_forks(philosopher);
		return ;
	}
	if (philosopher->argc == 6)
	{
		pthread_mutex_lock(&philosopher->meals_to_eat_mutex);
		*philosopher->meals_to_eat = *philosopher->meals_to_eat - 1;
		pthread_mutex_unlock(&philosopher->meals_to_eat_mutex);
	}
}

long	ft_helper_3(t_philos *philosopher)
{
	long	end_of_thinking;

	pthread_mutex_lock(&philosopher->last_meal_mutex);
	end_of_thinking = philosopher->time_to_eat + philosopher->time_to_sleep
		+ philosopher->last_meal + ((philosopher->time_to_die
				- philosopher->time_to_eat - philosopher->time_to_sleep)
			* 0.2);
	pthread_mutex_unlock(&philosopher->last_meal_mutex);
	return (end_of_thinking);
}

void	ft_philo_eat(t_philos *philosopher)
{
	long	end_of_meal;
	long	time;

	time = ft_get_time();
	end_of_meal = time + philosopher->time_to_eat;
	ft_helper_2(philosopher);
	pthread_mutex_lock(&philosopher->last_meal_mutex);
	philosopher->last_meal = time;
	pthread_mutex_unlock(&philosopher->last_meal_mutex);
	pthread_mutex_lock(philosopher->printf_mutex);
	printf("%ld: %d is eating.\n", (time - philosopher->start_time),
		philosopher->id);
	pthread_mutex_unlock(philosopher->printf_mutex);
	while (ft_get_time() < end_of_meal)
	{
		if (ft_check_if_dead(philosopher) == 1)
		{
			ft_unlock_forks(philosopher);
			return ;
		}
		usleep(100);
	}
	ft_unlock_forks(philosopher);
}

void	ft_philo_sleep(t_philos *philosopher)
{
	long	end_of_nap;
	long	time;

	time = ft_get_time();
	end_of_nap = time + philosopher->time_to_sleep;
	if (ft_check_if_dead(philosopher) == 1)
		return ;
	pthread_mutex_lock(&philosopher->meals_to_eat_mutex);
	if (*philosopher->meals_to_eat == 0)
		return ;
	pthread_mutex_unlock(&philosopher->meals_to_eat_mutex);
	pthread_mutex_lock(philosopher->printf_mutex);
	printf("%ld: %d is sleeping.\n", time - philosopher->start_time,
		philosopher->id);
	pthread_mutex_unlock(philosopher->printf_mutex);
	while (ft_get_time() < end_of_nap)
	{
		if (ft_check_if_dead(philosopher) == 1)
			return ;
		usleep(100);
	}
}

void	ft_philo_think(t_philos *philosopher)
{
	long	end_of_thinking;
	long	time;

	time = ft_get_time();
	if (ft_check_if_dead(philosopher) == 1)
		return ;
	end_of_thinking = ft_helper_3(philosopher);
	if (end_of_thinking < time)
		return ;
	else
	{
		pthread_mutex_lock(philosopher->printf_mutex);
		printf("%ld: %d started thinking.\n", time - philosopher->start_time,
			philosopher->id);
		pthread_mutex_unlock(philosopher->printf_mutex);
		while (ft_get_time() < end_of_thinking)
		{
			if (ft_check_if_dead(philosopher) == 1)
				return ;
			usleep(100);
		}
	}
}
