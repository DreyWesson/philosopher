/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:37:24 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/20 09:20:06 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philo.h"

/**
 *	@todo
 * Check inputs and take care of errors
 */

int	handle_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philos = malloc(sizeof(t_philo));
		data->philos->index = i + 1;
		data->philos->meal_qtd = i + 1;
		// data->philos->param = param;
		data->philos++;
	}
}

int	handle_forks(t_data *data)
{
	int	i;

	i = 0;
	// data->forks = malloc(sizeof(t_mutex) * (data->philo_num + 1));
	// if (!data->forks)
	// 	return (0);
	// (data->forks)[data->philo_num] = NULL;
	while (i < data->philo_num)
	{
		data->forks = malloc(sizeof(t_mutex));
		pthread_mutex_init(data->forks, NULL);
		data->forks++;
		i++;
	}
	return (1);
}

int	validate_value(long val, t_args type)
{
	if (val == 0 && type != MEAL_NUM)
		return (ft_error("Invalid value"), 0);
	if (type == PHILO_NUM && val > 200)
		return (ft_error("Too many philosophers"), 0);
	return (val);
}

int	set_args(char **argv, t_data *data)
{
	int		i;
	long	value;

	i = 1;
	data->min_meals = 2147483647;
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
	if (!set_args(argv, data))
		return (0);
	handle_forks(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (validator(argc, argv))
		return (1);
	if (!init_data(argv, &data))
		return (2);
	// printf("%d %llu %llu %llu %d\n", data.philo_num, data.time.to_die,
	// 	data.time.to_eat, data.time.to_sleep, data.min_meals);
	return (0);
}