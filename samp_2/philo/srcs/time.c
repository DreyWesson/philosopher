/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 20:24:22 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/10 18:53:58 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_microsec	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	delta_time(t_microsec init, t_microsec now)
{
	t_microsec	delta;

	if (now == 0)
		now = get_time();
	delta = now - init;
	return (delta / 1000);
}

void	sleeep_ms(int time)
{
	int	delay_factor;

	delay_factor = 200000000 / (200000 + DELAY);
	usleep(time * delay_factor);
}
