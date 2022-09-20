/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.ldr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:56:01 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/17 17:59:33 by pmeising         ###   ########.ldr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

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

void	ft_unlock_forks(t_philos *philosopher)
{
	if (philosopher->id % 2)
	{
		pthread_mutex_unlock(&philosopher->left_fork->mutex);
		pthread_mutex_unlock(&philosopher->right_fork->mutex);
	}
	else
	{
		pthread_mutex_unlock(&philosopher->right_fork->mutex);
		pthread_mutex_unlock(&philosopher->left_fork->mutex);
	}
}

void	ft_pick_up_forks(t_philos *philosopher)
{
	long	time;

	pthread_mutex_lock(&philosopher->philo_died_mutex);
	if (philosopher->philo_died == 1)
	{
		pthread_mutex_unlock(&philosopher->philo_died_mutex);
		return ;
	}
	pthread_mutex_unlock(&philosopher->philo_died_mutex);
	if (philosopher->id % 2)
	{
		pthread_mutex_lock(&philosopher->right_fork->mutex);
		pthread_mutex_lock(&philosopher->left_fork->mutex);
	}
	else
	{
		pthread_mutex_lock(&philosopher->left_fork->mutex);
		pthread_mutex_lock(&philosopher->right_fork->mutex);
	}
	pthread_mutex_lock(philosopher->printf_mutex);
	time = ft_get_time();
	printf("%ld: %d has taken fork %d.\n", (time - philosopher->start_time), philosopher->id, philosopher->left_fork->id);
	printf("%ld: %d has taken fork %d.\n", (time - philosopher->start_time), philosopher->id, philosopher->right_fork->id);
	pthread_mutex_unlock(philosopher->printf_mutex);
}

void	ft_philo_eat(t_philos *philosopher)
{
	long	end_of_meal;
	long	time;

	time = ft_get_time();
	end_of_meal = time + philosopher->time_to_eat;
	pthread_mutex_lock(&philosopher->last_meal_mutex);
	philosopher->last_meal = time;
	pthread_mutex_unlock(&philosopher->last_meal_mutex);
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
	pthread_mutex_lock(philosopher->printf_mutex);
	printf("%ld: %d is eating.\n", (time - philosopher->start_time), philosopher->id);
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
	pthread_mutex_lock(&philosopher->philo_died_mutex);
	if (philosopher->philo_died == 1)
	{
		pthread_mutex_unlock(&philosopher->philo_died_mutex);
		return ;
	}
	pthread_mutex_unlock(&philosopher->philo_died_mutex);

	pthread_mutex_lock(&philosopher->meals_to_eat_mutex);
	if (*philosopher->meals_to_eat == 0)
		return ;
	pthread_mutex_unlock(&philosopher->meals_to_eat_mutex);

	pthread_mutex_lock(philosopher->printf_mutex);
	printf("%ld: %d is sleeping.\n", time - philosopher->start_time, philosopher->id);
	pthread_mutex_unlock(philosopher->printf_mutex);
	while (ft_get_time() < end_of_nap)
	{
		pthread_mutex_lock(&philosopher->philo_died_mutex);
		if (philosopher->philo_died == 1)
		{
			pthread_mutex_unlock(&philosopher->philo_died_mutex);
			return ;
		}
		pthread_mutex_unlock(&philosopher->philo_died_mutex);
		usleep(100);
	}
}

void	ft_philo_think(t_philos *philosopher)
{
	long	end_of_thinking;
	long	time;

	time = ft_get_time();
	pthread_mutex_lock(&philosopher->philo_died_mutex);
	if (philosopher->philo_died == 1)
	{
		pthread_mutex_unlock(&philosopher->philo_died_mutex);
		return ;
	}
	pthread_mutex_unlock(&philosopher->philo_died_mutex);
	pthread_mutex_lock(&philosopher->last_meal_mutex);
	end_of_thinking = philosopher->time_to_eat + philosopher->time_to_sleep + 
	philosopher->last_meal + ((philosopher->time_to_die - philosopher->time_to_eat - 
	philosopher->time_to_sleep) * 0.2);
	pthread_mutex_unlock(&philosopher->last_meal_mutex);
	if (end_of_thinking < time)
		return ;
	else
	{
		pthread_mutex_lock(philosopher->printf_mutex);
		printf("%ld: %d started thinking.\n", time - philosopher->start_time, philosopher->id);
		pthread_mutex_unlock(philosopher->printf_mutex);
		while (ft_get_time() < end_of_thinking)
		{
			pthread_mutex_lock(&philosopher->philo_died_mutex);
			if (philosopher->philo_died == 1)
			{
				pthread_mutex_unlock(&philosopher->philo_died_mutex);
				return ;
			}
			pthread_mutex_unlock(&philosopher->philo_died_mutex);
			usleep(100);
		}
	}
}

void	*ft_routine(void *args)
{
	t_philos	*philosopher;

	philosopher = (t_philos *)args;
	while (1)
	{
		if (philosopher->id % 2 == 0)
			usleep(2000);
		// printf("Did philo die? %d\n", *philosopher->philo_died);
		if (ft_check_if_dead(philosopher) == 1)
			return (NULL);
		ft_pick_up_forks(philosopher);
		ft_philo_eat(philosopher);
		if (ft_check_if_dead(philosopher) == 1)
			return (NULL);
		ft_philo_sleep(philosopher);
		if (philosopher->argc == 6)
			if (*philosopher->meals_to_eat == 0)
				return (NULL);
		// Calculates the time until next meal has to be consumed.
		ft_philo_think(philosopher);
	}
	return (NULL);
}

int	ft_start_routine(t_prgrm *vars)
{
	int	i;
	int	j;

	j = 0;
	i = vars->nbr_of_philosophers;
	while (i > 0)
	{
		if (pthread_create(&vars->philos[j].thread, NULL, &ft_routine, &vars->philos[j]) != 0)
			return (1);
		j++;
		i--;
	}
	ft_waiter_routine(vars);
	return (0);
}
