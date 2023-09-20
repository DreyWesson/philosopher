/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:25:04 by lfrasson          #+#    #+#             */
/*   Updated: 2023/09/20 09:23:06 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = 0;
}

static void	print_death(t_param param)
{
	if (no_one_died(&param))
		return ;
	printf("%d %d died\n", delta_time(param.time.init, param.died.time),
		param.died.index);
}

static void	print_ate_enough(t_param param)
{
	if (someone_died(&param))
		return ;
	printf("All Philosophers ate at least %d times\n", param.must_eat);
}

int	main(int argc, char **argv)
{
	t_param	param;
	t_philo	**philos;
	t_mutex	**forks;
	int		status;

	ft_bzero(&param, sizeof(t_param));
	philos = NULL;
	forks = NULL;
	status = parse_input(argc, argv, &param);
	if (status == FAIL)
		return (status);
	printf("%d\n", param.died.index);
	initialize_structures(&philos, &forks, &param, param.number_of_philo);
	start_routines(philos, &param.time.init);
	print_death(param);
	print_ate_enough(param);
	free_structures(philos, forks);
	return (SUCCESS);
}
