/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:44:36 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/20 09:26:10 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// typedef unsigned long long int	t_microsec;
typedef u_int64_t		t_microsec;
typedef pthread_mutex_t	t_mutex;

typedef struct s_hand
{
	t_mutex				*left;
	t_mutex				*right;
}						t_hand;

typedef struct s_died
{
	t_mutex				mutex;
	int					index;
	t_microsec			time;
}						t_died;

typedef struct s_param
{
	t_died				died;
	t_time				time;
}						t_param;

typedef struct s_philo
{
	int					index;
	int					meal_qtd;
	t_microsec			last_meal;
	t_hand				hand;
	t_pthread			thread;
	t_param				*param;
}						t_philo;

typedef struct s_time
{
	t_microsec			init;
	t_microsec			to_die;
	t_microsec			to_eat;
	t_microsec			to_sleep;
}						t_time;

typedef struct s_data
{
	int					philo_num;
	t_time				time;
	int					min_meals;
	t_mutex				*forks;
	t_philo				*philos;
	// u_int64_t	start_time;
	// pthread_t		*tid;
	// int				dead;
	// int				finished;
	// t_philo			*philos;
	// pthread_mutex_t	*forks;
	// pthread_mutex_t	lock;
	// pthread_mutex_t	write;
}						t_data;

typedef enum e_args
{
	PHILO_NUM = 1,
	DEATH_TIME = 2,
	EAT_TIME = 3,
	SLEEP_TIME = 4,
	MEAL_NUM = 5

}						t_args;

int						ft_error(char *message);
int						parse_number(char *str);
int						validator(int argc, char **argv);
int						ft_atoi(const char *str);

#endif