/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:56:33 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/20 23:55:10 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define _PHILOSOPHERS_H
# define MAXINT 2147483647
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

// Forks structure______________________//

typedef struct s_forks
{
	int				id;
	pthread_mutex_t	mutex;
}				t_forks;

// Philo structure______________________//

typedef struct s_philos
{
	int				id;
	int				argc;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	int				*meals_to_eat;
	long			start_time;
	long			last_meal;
	int				philo_died;
	t_forks			*left_fork;
	t_forks			*right_fork;
	pthread_t		thread;
	pthread_mutex_t	philo_died_mutex;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	*printf_mutex;
	pthread_mutex_t	meals_to_eat_mutex;
}				t_philos;

//_______________Program variables structure_____________//

typedef struct s_prgrm
{
	pthread_t		*thread_ids;
	pthread_t		waiter;
	int				*meals_to_eat;
	long			start_time;
	int				argc;
	int				nbr_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	int				philo_died;
	t_philos		*philos;
	t_forks			*forks;
	pthread_mutex_t	printf_mutex;
	pthread_mutex_t	philo_died_mutex;
}				t_prgrm;

// Input check functions:

int		ft_atoi_phil(const char *nptr);

// Routine functions:

int		ft_start_routine(t_prgrm *vars);
void	*ft_routine(void *args);
void	*ft_waiter_routine(void *args);
void	ft_lone_thinker(t_prgrm *vars);

// Utils:

long	ft_get_time(void);
int		ft_free_structs(t_prgrm *vars);
int		ft_join_threads(t_prgrm *vars);

// Error handling:

int		ft_input_check(char **argv);
int		ft_check_values(t_prgrm *vars);
void	ft_error(int ecode);

#endif
