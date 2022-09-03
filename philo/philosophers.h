/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:56:33 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/03 15:24:19 by pmeising         ###   ########.fr       */
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
	int			*thread_ids;
	int			start_time;
	int			nbr_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_of_meals;
	// t_philos	*philos;
}				t_prgrm;

// typedef struct s_philos  // index structure
// {
// 	void		*vars;
// 	int			*index;
// }				t_philos;

// Error handling:

void	ft_error(int ecode);

#endif
