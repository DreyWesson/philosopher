/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:17:20 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/22 19:17:28 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_microsec	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (ft_error("gettimeofday() failed!\n"), 1);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}