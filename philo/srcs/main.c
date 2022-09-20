/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:57:51 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/20 23:59:20 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

// initializes the variables (vars) struct with the input values
// also takes time of start to compare to later time periods.

int	ft_init_vars_2(t_prgrm *vars)
{
	if (ft_check_values(vars) == 1)
	{
		ft_error(3);
		return (1);
	}
	vars->start_time = ft_get_time();
	if (vars->nbr_of_philosophers == 1)
	{
		ft_lone_thinker(vars);
		return (1);
	}
	vars->philos = malloc((sizeof(t_philos) * vars->nbr_of_philosophers) + 1);
	vars->forks = malloc((sizeof(t_forks) * vars->nbr_of_philosophers) + 1);
	pthread_mutex_init(&vars->printf_mutex, NULL);
	pthread_mutex_init(&vars->philo_died_mutex, NULL);
	vars->philo_died = 0;
	return (0);
}

int	ft_init_vars_1(t_prgrm *vars, int argc, char **argv)
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
		vars->meals_to_eat = malloc((sizeof(int) * vars->nbr_of_philosophers)
				+ 1);
	}
	else
	{
		vars->nbr_of_meals = 10;
		vars->meals_to_eat = malloc((sizeof(int) * vars->nbr_of_philosophers)
				+ 1);
	}
	if (ft_init_vars_2(vars) == 1)
		return (1);
	return (0);
}

void	ft_set_struct(t_prgrm *vars, int i)
{
	vars->philos[i].id = i + 1;
	vars->philos[i].argc = vars->argc;
	vars->philos[i].time_to_die = vars->time_to_die;
	vars->philos[i].time_to_eat = vars->time_to_eat;
	vars->philos[i].time_to_sleep = vars->time_to_sleep;
	vars->philos[i].start_time = vars->start_time;
	vars->philos[i].last_meal = ft_get_time();
	vars->philos[i].philo_died = 0;
	vars->philos[i].printf_mutex = &vars->printf_mutex;
	vars->forks[i].id = i + 1;
	vars->meals_to_eat[i] = vars->nbr_of_meals;
	vars->philos[i].meals_to_eat = &vars->meals_to_eat[i];
	vars->philos[i].left_fork = &vars->forks[i];
}

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
		pthread_mutex_init(&vars->philos[i].last_meal_mutex, NULL);
		pthread_mutex_init(&vars->philos[i].meals_to_eat_mutex, NULL);
		ft_set_struct(vars, i);
		if (i == 0)
			vars->philos[i].right_fork = &vars->forks[vars->nbr_of_philosophers
				- 1];
		else
			vars->philos[i].right_fork = &vars->forks[i - 1];
		nbr_philos--;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		ret;
	t_prgrm	vars;

	if ((argc == 5 || argc == 6) && ft_input_check(argv) == 0)
	{
		ret = ft_init_vars_1(&vars, argc, argv);
		if (ret != 0)
			return (0);
		if (ft_init_structs(&vars) == 1)
			return (0);
		if (ft_start_routine(&vars) == 1)
			return (0);
		if ((ft_join_threads(&vars)) != 0)
			return (0);
	}
	else
	{
		ft_error(1);
		return (0);
	}
	ft_free_structs(&vars);
	return (0);
}
