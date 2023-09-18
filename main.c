/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:37:24 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/17 22:48:55 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philosopher.h"

/**
 *	@todo
 * Check inputs and take care of errors
 */
int	validate_value(long val, t_args type)
{
	if (val == 0)
		return (ft_error("Invalid value"), 0);
	if (type == PHILO_NUM && val > 200)
		return (ft_error("Too many philosophers"), 0);
	return (val);
}

void	init_data(int argc, char **argv, t_data *data)
{
	int		i;
	long	value;

	i = 1;
	while (argv[i])
	{
		if (!*argv)
			break ;
		value = ft_atoi(argv[i]);
		if (i == PHILO_NUM && validate_value(value, PHILO_NUM))
			data->philo_num = value;
		else if (i == DEATH_TIME && validate_value(value, DEATH_TIME))
			data->death_time = (u_int64_t)value;
		else if (i == EAT_TIME && validate_value(value, EAT_TIME))
			data->eat_time = (u_int64_t)value;
		else if (i == SLEEP_TIME && validate_value(value, SLEEP_TIME))
			data->sleep_time = (u_int64_t)value;
		i++;
	}
	// printf("Testing\n");
	if (argc == 6)
	{
		data->meals_num = validate_value(ft_atoi(argv[5]), DEATH_TIME);
	}
	else
		data->meals_num = 2147483647;
}

int	main(int argc, char **argv)
{
	t_data data;

	if (validator(argc, argv))
		return (1);	
	init_data(argc, argv, &data);
	printf("%d %llu %llu %llu %d\n", data.philo_num, data.death_time,
		data.eat_time, data.sleep_time, data.meals_num);
	return (0);
}