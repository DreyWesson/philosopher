/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:26:57 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/22 19:25:38 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	validator(int argc, char **argv)
{
	if (!(argc == 6 || argc == 5))
		return (ft_error("Too few arguments..."), 1);
	while (*argv++)
	{
		if (*argv && is_digit(*argv))
			return (ft_error("Invalid argument"), 2);
	}
	return (0);
}

int	validate_value(long val, t_args type)
{
	if (val == 0 && type != MEAL_NUM)
		return (ft_error("Invalid value"), 0);
	if (type == PHILO_NUM && val > 200)
		return (ft_error("Too many philosophers"), 0);
	return (val);
}

void	clear_data(t_data	*data)
{
	if (data->tid)
		free(data->tid);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	clear_data(data);
}
