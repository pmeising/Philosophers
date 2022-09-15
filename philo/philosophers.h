/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:56:33 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/15 16:41:52 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define MAXINT 2147483647
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

// Philo structure______________________//

typedef	struct s_philos
{
	int			id;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_of_meals;
}				t_philos;

typedef struct s_prgrm
{
	pthread_t	*thread_ids; // stores the IDs of each thread at the index of its value
	int			*array; // stores numbers 0 through n in an array.
	long		start_time; // stores the starting time.
// inputs:
	int			nbr_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_of_meals;
	t_philos	*philos;
}				t_prgrm;

int		ft_atoi_phil(const char *nptr);

// Error handling:

int		ft_input_check(char **argv);
int		ft_check_values(t_prgrm *vars);
void	ft_error(int ecode);

#endif
