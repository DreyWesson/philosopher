/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:19:35 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/22 19:19:42 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*supervisor(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
			messages("died", philo);
		if (philo->chow == philo->data->min_meals)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->done++;
			philo->chow++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}