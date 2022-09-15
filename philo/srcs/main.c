/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:57:51 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/15 15:02:31 by pmeising         ###   ########.fr       */
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

int	ft_init_structs(t_prgrm *vars, int argc, char **argv)
{
	vars->nbr_of_philosophers = ft_atoi_phil(argv[1]);
	vars->time_to_die = ft_atoi_phil(argv[2]);
	vars->time_to_eat = ft_atoi_phil(argv[3]);
	vars->time_to_sleep = ft_atoi_phil(argv[4]);
	if (argc == 6)
		vars->nbr_of_meals = ft_atoi_phil(argv[5]);
	if (ft_check_values(vars) == 1)
	{
		ft_error(3);
		return (1);
	}
	vars->start_time = ft_get_time();
	printf("time: %ld\n", vars->start_time);
	return (0);
}

int	main(int argc, char **argv)
{
	t_prgrm	vars;

	if ((argc == 5 || argc == 6) && ft_input_check(argv) == 0)
	{
		if (ft_init_structs(&vars, argc, argv) == 1)
			return (1);
	}
	else
		ft_error(1);
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