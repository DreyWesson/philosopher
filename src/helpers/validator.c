/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:35:23 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/19 17:23:27 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	parse_number(char *str)
{
	char	tmp;

	while (*str)
	{
		tmp = *str++;
		if (tmp < 48 || tmp > 57)
			return (2);
	}
	return (0);
}

int	validator(int argc, char **argv)
{
	if (!(argc == 6 || argc == 5))
		return (ft_error("Too few arguments..."), 1);
	while (*argv++)
	{
		if (*argv && parse_number(*argv))
			return (ft_error("Invalid argument"), 2);
	}
	return (0);
}
