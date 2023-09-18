/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:09:41 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/11 16:00:59 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define NOT_NUMBER -2
#define INVALID_NUMBER -3
#define INVALID_ARGC -4

int	print_error(int code)
{
	printf("Error\n");
	if (code == INVALID_ARGC)
		printf("Incorrect number of arguments\n");
	if (code == NOT_NUMBER)
		printf("Non-numeric argument\n");
	if (code == INVALID_NUMBER)
		printf("Negative number\n");
	printf("Usage: philo number_of_philosophers time_to_die time_to_eat ");
	printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (FAIL);
}

static int	parse_number(char *str_number, int *number)
{
	long	lnumber;

	if (!is_string_number(str_number))
		return (print_error(NOT_NUMBER));
	lnumber = ft_atol(str_number);
	*number = (int)lnumber;
	if (lnumber < 0 || !is_integer(lnumber))
		return (print_error(INVALID_NUMBER));
	return (SUCCESS);
}

int	parse_arguments(char **argv, t_param *param)
{
	if (parse_number(*argv++, &param->number_of_philo))
		return (FAIL);
	if (parse_number(*argv++, &param->time.to_die))
		return (FAIL);
	if (parse_number(*argv++, &param->time.to_eat))
		return (FAIL);
	if (parse_number(*argv++, &param->time.to_sleep))
		return (FAIL);
	param->must_eat = 0;
	if (!*argv)
		return (SUCCESS);
	if (parse_number(*argv, &param->must_eat))
		return (FAIL);
	return (SUCCESS);
}

static int	check_number_of_arguments(int argc)
{
	if (argc == 6 || argc == 5)
		return (SUCCESS);
	print_error(INVALID_ARGC);
	return (FAIL);
}

int	parse_input(int argc, char **argv, t_param *param)
{
	if (check_number_of_arguments(argc))
		return (FAIL);
	if (parse_arguments(argv + 1, param))
		return (FAIL);
	return (SUCCESS);
}
