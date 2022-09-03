/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:01:41 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/03 15:25:07 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	ft_init_philos(t_prgrm *vars)
{
	int	i;

	i = vars->nbr_of_philosophers;
	while (i > 0)
	{
		
	}
}

void	ft_init_struct_5(t_prgrm *vars, char **argv)
{
	vars->nbr_of_philosophers = atoi(argv[1]);
	vars->time_to_die = atoi(argv[2]);
	vars->time_to_eat = atoi(argv[3]);
	vars->time_to_sleep = atoi(argv[4]);
	if (argv[5])
		vars->nbr_of_meals = atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	struct s_prgrm	*vars;

	vars = NULL;
	if (argc == 5 || argc == 6)
	{
		ft_init_struct_5(vars, argv);
		ft_init_philos(vars);
	}
	ft_error(1);
	return (0);
}
