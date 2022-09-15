/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:45:26 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/15 15:10:05 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_is_nbr(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9' || j > 9)
			{
				ft_error(2);
				return (1);
			}
			if (i == 1 && j > 2)
				ft_error(2);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_input_check(char **argv)
{
	if (ft_is_nbr(argv) == 1)
		return (1);
	return (0);
}

int	ft_check_values(t_prgrm *vars)
{
	if (vars->nbr_of_philosophers > 200 || vars->nbr_of_philosophers < 1)
		return (1);
	else if (vars->nbr_of_meals < 1 || vars->nbr_of_meals > MAXINT)
		return (1);
	else if (vars->time_to_die < 1 || vars->time_to_die > MAXINT)
		return (1);
	else if (vars->time_to_eat < 1 || vars->time_to_die > MAXINT)
		return (1);
	else if (vars->time_to_sleep < 1 || vars->time_to_die > MAXINT)
		return (1);
	return (0);
}
