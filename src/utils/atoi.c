/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:14:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/17 18:14:32 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philosopher.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	nbr;
	int		is_neg;

	i = 0;
	nbr = 0;
	is_neg = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
		is_neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if (is_neg == 1)
		return (-nbr);
	return (nbr);
}
