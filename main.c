/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:37:24 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/20 18:29:02 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philo.h"

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