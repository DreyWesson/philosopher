/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:14:44 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/22 19:30:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_thread(t_data *data)
{
	int			i;
	pthread_t	t0;

	i = -1;
	data->time.init = get_time();
	if (data->min_meals > 0)
	{
		if (pthread_create(&t0, NULL, &monitor, &data->philos[0]))
			return (ft_error("Create thread fail"));
	}
	while (++i < data->philo_num)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]))
			return (ft_error("Create thread fail"));
		ft_sleep(1);
	}
	i = -1;
	while (++i < data->philo_num)
	{
		if (pthread_join(data->tid[i], NULL))
			return (ft_error("Create thread fail"));
	}
	return (0);
}