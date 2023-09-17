/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:37:24 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/17 19:07:11 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philosopher.h"

/**
 *	@todo
 * Check inputs and take care of errors
 */
void	init_data(char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!*argv)
			break ;
		if (i == PHILO_NUM)
			data->philo_num = ft_atoi(argv[PHILO_NUM]);
		else if (i == DEATH_TIME)
			data->death_time = ft_atoi(argv[DEATH_TIME]);
		else if (i == EAT_TIME)
			data->eat_time = ft_atoi(argv[EAT_TIME]);
		else if (i == SLEEP_TIME)
			data->sleep_time = ft_atoi(argv[SLEEP_TIME]);
		i++;
	}
	if (argv[MEAL_NUM])
		data->meals_num = ft_atoi(argv[MEAL_NUM]);
	else
		data->meals_num = 2147483647;
}

int	main(int argc, char **argv)
{
	t_data data;

	if (validator(argc, argv))
		return (1);
	init_data(argv, &data);
	printf("%d %llu %llu %llu %d\n", data.philo_num, data.death_time,
		data.eat_time, data.sleep_time, data.meals_num);
	return (0);
}