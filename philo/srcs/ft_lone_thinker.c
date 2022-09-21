/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lone_thinker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:54:08 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/21 11:09:59 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_lone_thinker(t_prgrm *vars)
{
	printf("%ld: 1 has taken fork 1.\n", ft_get_time() - vars->start_time);
	usleep((vars->time_to_die) * 1000);
	printf("%ld: 1 died.\n", ft_get_time() - vars->start_time);
	free(vars->meals_to_eat);
	return ;
}
