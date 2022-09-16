/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:56:01 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/16 17:26:16 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*ft_routine(void *args)
{
	t_philos	*philosopher;

	philosopher = (t_philos *)args;
	// printf("%.2ld: ", ft_get_time() - philosopher->start_time);
	// if (philosopher->id == 3)
	// 	usleep(1000);
	printf("%ld: This is my ID: %d\nI have fork # %d to my left\nand fork # %d to my right\n", (ft_get_time() - philosopher->start_time), philosopher->id, philosopher->left_fork->id, philosopher->right_fork->id);
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
	return (0);
}
