/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:40:44 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/11 12:33:00 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	someone_died(t_param *param)
{
	if (param->died.index == 0)
		return (FALSE);
	return (TRUE);
}

int	no_one_died(t_param *param)
{
	return (!someone_died(param));
}

static int	have_time_to_eat(t_philo *philo)
{
	if (delta_time(philo->last_meal, FALSE) < philo->param->time.to_die)
		return (TRUE);
	return (FALSE);
}

static void	*death_control(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (have_time_to_eat(philo) && no_one_died(philo->param)
		&& not_ate_enough(philo))
		continue ;
	if (already_ate_enough(philo) || someone_died(philo->param))
		return (SUCCESS);
	pthread_mutex_lock(&philo->param->died.mutex);
	philo->param->died.time = get_time();
	philo->param->died.index = philo->index;
	pthread_mutex_unlock(&philo->param->died.mutex);
	pthread_mutex_unlock(philo->hand.left);
	return (SUCCESS);
}

void	create_control_thread(t_philo *philo)
{
	t_pthread	thread;

	pthread_create(&thread, NULL, death_control, philo);
	pthread_detach(thread);
}
