/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:47:54 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/03 15:25:44 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	ft_error(int ecode)
{
	if (ecode == 1)
	{
		printf("Sorry, wrong input syntax, please try again with min. 4 arguments this time. ;)\n");
	}
	// printf("ecode: %d\n", ecode);
}
