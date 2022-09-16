/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:56:33 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/16 17:25:27 by pmeising         ###   ########.fr       */
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

// Forks structure______________________//

typedef struct s_forks
{
	int			id;
}				t_forks;

// Philo structure______________________//

typedef	struct s_philos
{
	int			id;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_of_meals;
	long		start_time;
	long		last_meal;
	pthread_t	thread;
	//_________forks_________//
	t_forks		*left_fork;
	t_forks		*right_fork;

}				t_philos;


// Program variables structure_____________//

typedef struct s_prgrm
{
	pthread_t	*thread_ids; // stores the IDs of each thread at the index of its value
	int			*array; // stores numbers 0 through n in an array.
	long		start_time; // stores the starting time.
// inputs:
	int			argc;
	int			nbr_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_of_meals;
	t_philos	*philos;
	t_forks		*forks;
}				t_prgrm;

// Input check functions:

int		ft_atoi_phil(const char *nptr);

// Routine functions:

int		ft_start_routine(t_prgrm *vars);
void	*ft_routine(void *args);
int		ft_join_threads(t_prgrm *vars);

// Time management:

long	ft_get_time();

// Error handling:

int		ft_input_check(char **argv);
int		ft_check_values(t_prgrm *vars);
void	ft_error(int ecode);

#endif
