/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:47:54 by pmeising          #+#    #+#             */
/*   Updated: 2022/09/20 20:25:47 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_error(int ecode)
{
	if (ecode == 1)
	{
		printf("Sorry, wrong input syntax.\n");
	}
	else if (ecode == 2)
		printf("Invalid argument.\n");
	else if (ecode == 3)
		printf("Invalid value passed as argument, out of bounds.\n");
	// printf("ecode: %d\n", ecode);
}
