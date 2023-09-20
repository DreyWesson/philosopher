/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:37:24 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/20 17:13:15 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philo.h"

/**
 *	@todo
 * Check inputs and take care of errors
 */
int	validate_value(long val, t_args type)
{
	if (val == 0 && type != MEAL_NUM)
		return (ft_error("Invalid value"), 0);
	if (type == PHILO_NUM && val > 200)
		return (ft_error("Too many philosophers"), 0);
	return (val);
}

int	handle_memory(t_data *data)
{
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	data->tid = malloc(sizeof(pthread_t) * data->philo_num);
	if (!data->tid)
		return (ft_error("Malloc failed!"), 0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
		return (ft_error("Malloc failed!"), 0);
	data->philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philos)
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
			data->time.to_die = (u_int64_t)value;
		else if (i == EAT_TIME)
			data->time.to_eat = (u_int64_t)value;
		else if (i == SLEEP_TIME)
			data->time.to_sleep = (u_int64_t)value;
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
	// if ()
	// 	return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (validator(argc, argv))
		return (1);	
	if (!init_data(argv, &data))
		return (2);
	printf("%d %llu %llu %llu %d\n", data.philo_num, data.time.to_die,
		data.time.to_eat, data.time.to_sleep, data.min_meals);
	return (0);
}