/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:16:17 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/22 19:16:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*monitor(void *data_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) data_pointer;
	pthread_mutex_lock(&philo->data->write);
	pthread_mutex_unlock(&philo->data->write);
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->done >= philo->data->philo_num)
			philo->data->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}