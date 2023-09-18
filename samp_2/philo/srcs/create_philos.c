/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:01:46 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/11 12:13:28 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_hands(t_philo *philo, t_mutex **forks)
{
	philo->hand.left = forks[philo->index - 1];
	philo->hand.right = forks[philo->index];
	if (philo->hand.right == NULL)
		philo->hand.right = forks[0];
}

static void	initialize_philos(t_philo **philos, t_mutex **forks, t_param *param)
{
	int		index;

	index = 0;
	while (philos[index])
	{
		philos[index] = malloc(sizeof(t_philo));
		philos[index]->index = index + 1;
		philos[index]->meal_qtd = 0;
		philos[index]->param = param;
		set_hands(philos[index], forks);
		index++;
	}
}

int	create_philos(t_philo ***philos, t_mutex **forks, t_param *param, int size)
{
	*philos = malloc(sizeof(t_philo *) * (size + 1));
	if (!*philos)
		return (FAIL);
	(*philos)[size] = NULL;
	initialize_philos(*philos, forks, param);
	return (SUCCESS);
}
