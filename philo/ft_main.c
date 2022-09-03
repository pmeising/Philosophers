/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:01:41 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/03 16:46:23 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	*ft_routine(void *vars)
{
	int	id;
	int	i;

	i = 0;
	while (((t_prgrm *)vars)->array[i] == -1)
		i++;
	printf("array[0]: %d\n", ((t_prgrm *)vars)->array[0]);
	printf("array[1]: %d\n", ((t_prgrm *)vars)->array[1]);
	printf("array[i]: %d i: %d\n", ((t_prgrm *)vars)->array[i], i);
	id = ((t_prgrm *)vars)->array[i];
	printf("Thread ID: %d\n", id);
	return (NULL);
}

void	ft_init_philos(t_prgrm *vars)
{
	int	i;

	i = 0;
	while (i < vars->nbr_of_philosophers)
	{
		vars->array[i] = i;
		pthread_create(&vars->thread_ids[i], NULL, &ft_routine, vars);
		i++;
	}
	// free(array);
}

void	ft_init_struct_5(t_prgrm *vars, char **argv)
{
	int	i;

	i = 0;
	vars->nbr_of_philosophers = atoi(argv[1]);
	vars->time_to_die = atoi(argv[2]);
	vars->time_to_eat = atoi(argv[3]);
	vars->time_to_sleep = atoi(argv[4]);
	vars->thread_ids = malloc((sizeof(pthread_t) * vars->nbr_of_philosophers) + 1);
	vars->array = malloc(sizeof(int) * vars->nbr_of_philosophers + 1);
	while(i < vars->nbr_of_philosophers)
	{
		printf("i: %d\n", i);
		vars->array[i] = -1;
		printf("array[i]: %d\n", vars->array[i]);
		i++;
	}
	// if (argv[5])
	// 	vars->nbr_of_meals = atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	struct s_prgrm	*vars;

	vars = malloc(sizeof(struct s_prgrm));
	if (argc == 5 || argc == 6)
	{
		ft_init_struct_5(vars, argv);
		ft_init_philos(vars);
		pthread_join(vars->thread_ids[0], NULL);
	}
	else
		ft_error(1);
	return (0);
}
