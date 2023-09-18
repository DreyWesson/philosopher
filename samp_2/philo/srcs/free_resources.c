/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:21:15 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/08 20:23:16 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_null(void *pointer)
{
	if (pointer)
		free(pointer);
	pointer = NULL;
}

static void	free_double_pointer(void **pointer)
{
	int		i;
	void	**next;

	i = 0;
	if (!pointer)
		return ;
	next = pointer;
	while (*next)
	{
		free_null(*next);
		next++;
	}
	free_null(pointer);
}

static void	destroy_mutex(t_mutex **forks)
{
	while (*forks)
	{
		pthread_mutex_destroy(*forks);
		forks++;
	}
}

void	free_structures(t_philo	**philos, t_mutex **forks)
{
	destroy_mutex(forks);
	free_double_pointer((void **)philos);
	free_double_pointer((void **)forks);
}
