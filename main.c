/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:37:24 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/17 16:48:52 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philosopher.h"

/**
 *	@todo
 * Check inputs and take care of errors
 */

int	ft_error(char *message)
{
	printf("\033[1;31m"
			"Error\n"
			"\033[0m");
	printf("\033[3m\033[2;37m"
			" %s\n"
			"\033[0m",
			message);
	return (0);
}

int	parse_number(char *str)
{
	char	tmp;

	tmp = *str;
	while (*str)
	{
		tmp = *str++;
		if (tmp < 48 || tmp > 57)
			return (2);
	}
	return (0);
}

void	validate_args(char **argv)
{
	while (*argv++)
	{
		if (*argv && parse_number(*argv))
		{
			ft_error("Invalid argument");
			break ;
		}
	}
}

int	validator(int argc, char **argv)
{
	if (!(argc == 6 || argc == 5))
		return (ft_error("Too few arguments..."), 1);
	validate_args(argv);
	return (0);
}

int	main(int argc, char **argv)
{
	validator(argc, argv);
	return (0);
}