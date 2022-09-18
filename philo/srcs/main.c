/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:57:51 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/18 22:22:30 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// I add the seconds * 1000 to the microseconds / 1000 to get one big number 
// containing the miliseconds of the moment of start.

long	ft_get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)(tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

// initializes the variables (vars) struct with the input values
// also takes time of start to compare to later time periods.

int	ft_init_vars(t_prgrm *vars, int argc, char **argv)
{
	vars->argc = argc;
	vars->philo_died = 0;
	vars->nbr_of_philosophers = ft_atoi_phil(argv[1]);
	vars->time_to_die = (ft_atoi_phil(argv[2]));
	vars->time_to_eat = (ft_atoi_phil(argv[3]));
	vars->time_to_sleep = (ft_atoi_phil(argv[4]));
	if (argc == 6)
	{
		vars->nbr_of_meals = ft_atoi_phil(argv[5]);
		vars->meals_to_eat = malloc((sizeof(int) * vars->nbr_of_meals) + 1);
	}
	if (ft_check_values(vars) == 1)
	{
		ft_error(3);
		return (1);
	}
	vars->start_time = ft_get_time();
	printf("time: %2.ld\n", vars->start_time);
	vars->philos = malloc((sizeof(t_philos) * vars->nbr_of_philosophers) + 1);
	vars->forks = malloc((sizeof(t_forks) * vars->nbr_of_philosophers) + 1);
	pthread_mutex_init(&vars->printf_mutex, NULL);
	pthread_mutex_init(&vars->philo_died_mutex, NULL);
	pthread_mutex_init(&vars->meals_to_eat_mutex, NULL);
	vars->philo_died = 0;
	return (0);
}

// For Philosopher 2, the position in the array of structs is 1. This also 
// corresponds to this philosophers ***left*** fork. (Unless it is philosopher
// n).

int	ft_init_structs(t_prgrm *vars)
{
	int			i;
	int			nbr_philos;

	i = 0;
	nbr_philos = vars->nbr_of_philosophers;
	while (nbr_philos > 0)
	{
		pthread_mutex_init(&vars->forks[i].mutex, NULL);
		pthread_mutex_init(&vars->philos[i].philo_died_mutex, NULL);
		pthread_mutex_init(&vars->philos[i].meals_to_eat_mutex, NULL);
		vars->philos[i].id = i + 1;
		vars->philos[i].time_to_die = vars->time_to_die;
		vars->philos[i].time_to_eat = vars->time_to_eat;
		vars->philos[i].time_to_sleep = vars->time_to_sleep;
		vars->philos[i].start_time = vars->start_time;
		vars->philos[i].last_meal = ft_get_time();
		vars->philos[i].philo_died = &vars->philo_died;
		vars->philos[i].printf_mutex = &vars->printf_mutex;
		vars->forks[i].id = i + 1;
		vars->meals_to_eat[i] = vars->philos[i].nbr_of_meals;
		if (vars->argc == 6)
			vars->philos[i].meals_to_eat = &vars->meals_to_eat[i];
		// printf("Mutex created.\n");
		vars->philos[i].left_fork = &vars->forks[i];
		if (i == 0)
			vars->philos[i].right_fork = &vars->forks[vars->nbr_of_philosophers - 1];
		else
			vars->philos[i].right_fork = &vars->forks[i - 1];
		nbr_philos--;
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
	free(vars->philos);
	free(vars->forks);
	pthread_mutex_destroy(&vars->printf_mutex);
	pthread_mutex_destroy(&vars->philo_died_mutex);
	return (0);
}

int	main(int argc, char **argv)
{
	t_prgrm	vars;

	if ((argc == 5 || argc == 6) && ft_input_check(argv) == 0)
	{
		if (ft_init_vars(&vars, argc, argv) == 1)
		{
			printf("Initialization of vars failed.\n");
			return (0);
		}
		printf("Initialized the vars struct.\n");
		if (ft_init_structs(&vars) == 1)
		{
			printf("Initialization of philos structs failed.\n");
			return (0);
		}
		printf("Initialized the philos structs.\n");
		if (ft_start_routine(&vars) == 1)
		{
			printf("Routines returned error.\n");
			return (0);
		}
		if ((ft_join_threads(&vars)) != 0)
		{
			printf("Threads couldn't be joined.\n");
			return (0);
		}
	}
	else
		ft_error(1);
	ft_free_structs(&vars);
	return (0);
}

// // "i" passes through the number of the philosopher to the thread to be 'self-aware'

// int	ft_init_threads(t_philos number)
// {
// 	pthread_t	newthread;
// 	int			result;

// 	result = pthread_create(&newthread, NULL, ft_routine(), vars);
// 	return (result);
// }

// // philo nbrs start at 1, not at 0. First Philo is nbr 1, not 0. subject p. 6

// void	ft_init_philos(t_prgrm *vars, int n)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= n)
// 	{
// 		ft_init_threads(vars->philos[i]);
// 		i++;
// 	}
// }

// void	ft_init_struct(t_prgrm *vars, char **argv)
// {
// 	int	i;

// 	i = 0;
// 	gettimeofday(vars->start_time, NULL);
// 	printf("Start time: %ld\n", vars->start_time);
// 	vars->philos = malloc((sizeof(t_philos) * vars->nbr_of_philosophers) + 1);
// }