/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:16:08 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/11 15:59:08 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <limits.h>

# define TRUE	1
# define FALSE	0

int	ft_isdigit(int c);
int	ft_isspace(int c);
int	ft_atol(const char *str);
int	is_string_number(char *string);
int	is_integer(long number);

#endif
