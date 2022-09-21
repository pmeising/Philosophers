/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:53:04 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/21 10:54:27 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

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

	if (ft_check_if_dead(philosopher) == 1)
		return ;
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
	printf("%ld: %d has taken fork %d.\n", (time - philosopher->start_time),
		philosopher->id, philosopher->left_fork->id);
	printf("%ld: %d has taken fork %d.\n", (time - philosopher->start_time),
		philosopher->id, philosopher->right_fork->id);
	pthread_mutex_unlock(philosopher->printf_mutex);
}

void	*ft_routine(void *args)
{
	t_philos	*philosopher;

	philosopher = (t_philos *)args;
	while (1)
	{
		if (philosopher->id % 2 == 0)
			usleep(2000);
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
		if (pthread_create(&vars->philos[j].thread, NULL, &ft_routine,
				&vars->philos[j]) != 0)
			return (1);
		j++;
		i--;
	}
	ft_waiter_routine(vars);
	return (0);
}
