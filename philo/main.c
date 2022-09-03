/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:57:51 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/03 14:13:32 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

// "i" passes through the number of the philosopher to the thread to be 'self-aware'

int	ft_init_threads(t_philos number)
{
	pthread_t	newthread;
	int			result;

	result = pthread_create(&newthread, NULL, ft_routine(), vars);
	return (result);
}

// philo nbrs start at 1, not at 0. First Philo is nbr 1, not 0. subject p. 6

void	ft_init_philos(t_prgrm *vars, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		ft_init_threads(vars->philos[i]);
		i++;
	}
}

void	ft_init_struct(t_prgrm *vars, char **argv)
{
	int	i;

	i = 0;
	gettimeofday(vars->start_time, NULL);
	printf("Start time: %ld\n", vars->start_time);
	vars->philos = malloc((sizeof(t_philos) * vars->nbr_of_philosophers) + 1);
}

int	main(int argc, char **argv)
{
	t_prgrm *vars;

	if (argc == 5)
	{
		ft_init_struct(&vars, &index);
		ft_initialize_philosophers(&vars, &index, argv[1]);
		// pthread_join(newthread, NULL);
	}
	ft_error(1);
	return (0);
}
