/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:56:33 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/15 14:06:36 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

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
}				t_prgrm;

// Error handling:

int		ft_atoi_phil(const char *nptr);
void	ft_error(int ecode);

#endif
