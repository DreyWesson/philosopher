/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:08:35 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/11 12:33:23 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	t_mutex	*first;
	t_mutex	*second;

	first = philo->hand.left;
	second = philo->hand.right;
	pthread_mutex_lock(first);
	print("has taken a fork\n", philo);
	pthread_mutex_lock(second);
	print("has taken a fork\n", philo);
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->hand.left);
	pthread_mutex_unlock(philo->hand.right);
}

int	already_ate_enough(t_philo *philo)
{
	if (philo->param->must_eat == 0)
		return (FALSE);
	if (philo->meal_qtd < philo->param->must_eat)
		return (FALSE);
	return (TRUE);
}

int	not_ate_enough(t_philo *philo)
{
	return (!already_ate_enough(philo));
}

int	eating(t_philo *philo)
{
	if (someone_died(philo->param) || already_ate_enough(philo))
		return (FALSE);
	take_forks(philo);
	philo->last_meal = get_time();
	print("is eating\n", philo);
	sleeep_ms(philo->param->time.to_eat);
	drop_forks(philo);
	philo->meal_qtd++;
	return (TRUE);
}
