/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:19:38 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/20 20:00:38 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void init_philos(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_num)
    {
        data->philos[i].id = i + 1;
        data->philos[i].data = data;
        data->philos[i].time_to_die = data->time.to_die;
        data->philos[i].chow = 0;
        data->philos[i].eating = 0;
        data->philos[i].status = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
        i++;
    }
}

void init_forks(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_num)
    {
		/// @note: error checker here
		pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    i = 0;
    while (i < data->philo_num)
    {
		data->philos[i].hand.left = &data->forks[i];
        if (i == 0)
		    data->philos[i].hand.right = &data->forks[data->philo_num - 1];
        else
		    data->philos[i].hand.right = &data->forks[i - 1];
        i++;
    }
}

int	handle_memory(t_data *data)
{
	/// @note: error checker here
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	data->tid = malloc(sizeof(pthread_t) * data->philo_num);
	if (!data->tid)
		return (ft_error("Malloc failed!"), 0);
	data->philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philos)
		return (ft_error("Malloc failed!"), 0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
		return (ft_error("Malloc failed!"), 0);
	return (1);
}

int set_args(char **argv, t_data *data)
{
	int		i;
	long	value;

	i = 1;
	data->min_meals = 2147483647;
	data->dead = 0;
	data->done = 0;
	while (argv[i])
	{
		value = validate_value(ft_atoi(argv[i]), i);
		if (value == 0 && i != MEAL_NUM)
			return (0);
		if (i == PHILO_NUM)
			data->philo_num = value;
		else if (i == DEATH_TIME)
			data->time.to_die = (t_microsec)value;
		else if (i == EAT_TIME)
			data->time.to_eat = (t_microsec)value;
		else if (i == SLEEP_TIME)
			data->time.to_sleep = (t_microsec)value;
		if ((i + 1) == 6)
			data->min_meals = ft_atoi(argv[5]);
		i++;
	}
	return (1);
}

int	init_data(char **argv, t_data *data)
{
	if (!set_args(argv, data) || !handle_memory(data))
		return (0);
    init_forks(data);
	init_philos(data);
	return (1);
}