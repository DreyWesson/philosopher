/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:15:06 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/11 16:00:10 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_string_number(char *string)
{
	if (*string == '-')
		string++;
	while (*string)
		if (!ft_isdigit(*string++))
			return (FALSE);
	return (TRUE);
}

int	is_integer(long number)
{
	if (number > INT_MAX)
		return (FALSE);
	if (number < INT_MIN)
		return (FALSE);
	return (TRUE);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ')
		return (TRUE);
	return (FALSE);
}

int	ft_atol(const char *str)
{
	long long	nbr;
	int			sign;

	nbr = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
		nbr = nbr * 10 + *str++ - '0';
	return ((long)(sign * nbr));
}
