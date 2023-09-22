/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:37:24 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/22 19:56:50 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philo.h"

int single_philo(t_data *data)
{
	data->time.init = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
		return (ft_error("Thread error"), 1);
	pthread_detach(data->tid[0]);
	while (data->dead == 0)
		ft_sleep(0);
	ft_exit(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (validator(argc, argv))
		return (1);
	if (!init_data(argv, &data))
		return (2);

	if (data.philo_num == 1)
		return (single_philo(&data));
	if (init_thread(&data))
		return (4);
	ft_exit(&data);
	return (0);
}