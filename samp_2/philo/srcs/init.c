/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:56:31 by lfrasson          #+#    #+#             */
/*   Updated: 2023/09/20 08:02:20 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	initialize_forks(t_mutex **forks)
{
	printf("", );
	while (*forks)
	{
		printf("Here\n");
		*forks = malloc(sizeof(t_mutex));
		pthread_mutex_init(*forks, NULL);
		forks++;
	}
}

static int	create_forks(t_mutex ***forks, int size)
{
	*forks = malloc(sizeof(t_mutex *) * (size + 1));
	if (!*forks)
		return (FAIL);
	(*forks)[size] = NULL;
	initialize_forks(*forks);
	return (SUCCESS);
}

int	initialize_structures(t_philo ***philos, t_mutex ***forks, t_param *param,
		int size)
{
	if (create_forks(forks, size) == FAIL)
		return (FAIL);
	if (create_philos(philos, *forks, param, size) == FAIL)
		return (FAIL);
	pthread_mutex_init(&param->died.mutex, NULL);
	return (SUCCESS);
}
