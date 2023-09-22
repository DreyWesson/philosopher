/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:21:57 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/22 19:30:18 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_sleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->hand.right);
	messages("has taken a fork", philo);
	pthread_mutex_lock(philo->hand.left);
	messages("has taken a fork", philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->hand.left);
	pthread_mutex_unlock(philo->hand.right);
	messages("is sleeping", philo);
	ft_sleep(philo->data->time.to_sleep);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = get_time() + philo->data->time.to_die;
	messages("is eating", philo);
	philo->chow++;
	ft_sleep(philo->data->time.to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_forks(philo);
}