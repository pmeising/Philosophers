/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:57:51 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/14 21:36:06 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

static int	ft_is_negative(char *nptr, int i)
{
	if (nptr[i] == '-')
		return (-1);
	else if (nptr[i] == '+')
		return (1);
	return (0);
}

int	ft_atoi_phil(const char *nptr)
{
	int		i;
	int		is_negative;
	int		nbr;

	nbr = 0;
	is_negative = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
			i++;
	is_negative = ft_is_negative((char *)nptr, i);
	if (is_negative != 0)
		i++;
	if (!(nptr[i] > 47 && nptr[i] < 58))
		return (0);
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
	}
	if (is_negative != 0)
		return (nbr * is_negative);
	return (nbr);
}

long	ft_get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)(tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	// return((long)tv.tv_sec);
}

void	ft_init_structs(t_prgrm *vars, int argc, char **argv)
{
	vars->nbr_of_philosophers = ft_atoi_phil(argv[1]);
	vars->time_to_die = ft_atoi_phil(argv[2]);
	vars->time_to_eat = ft_atoi_phil(argv[3]);
	vars->time_to_sleep = ft_atoi_phil(argv[4]);
	if (argc == 6)
		vars->nbr_of_meals = ft_atoi_phil(argv[5]);
	printf("time: %ld\n", ft_get_time());
}

int	main(int argc, char **argv)
{
	t_prgrm	vars;

	if (argc == 5 || argc == 6)
	{
		ft_init_structs(&vars, argc, argv);
		// ft_initialize_philosophers(&vars, argv[1]);
		// pthread_join(newthread, NULL);
	}
	// ft_error(1);
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