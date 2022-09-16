/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:51:34 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/16 15:55:55 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_join_threads(t_prgrm *vars)
{
	int	i;

	i = 0;
	while (i < vars->nbr_of_philosophers)
	{
		if (pthread_join(vars->philos[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
