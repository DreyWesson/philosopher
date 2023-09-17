/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:44:36 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/17 18:53:37 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int			philo_num;
	u_int64_t	death_time;
	u_int64_t	eat_time;
	u_int64_t	sleep_time;
	int			meals_num;
	// u_int64_t	start_time;
	// pthread_t		*tid;
	// int				dead;
	// int				finished;
	// t_philo			*philos;
	// pthread_mutex_t	*forks;
	// pthread_mutex_t	lock;
	// pthread_mutex_t	write;
}				t_data;

enum			e_args
{
	PHILO_NUM = 1,
	DEATH_TIME = 2,
	EAT_TIME = 3,
	SLEEP_TIME = 4,
	MEAL_NUM = 5

};

int				ft_error(char *message);
int				parse_number(char *str);
int				validator(int argc, char **argv);
int				ft_atoi(const char *str);

#endif