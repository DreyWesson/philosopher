/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:36:41 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/11 16:01:36 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "utils.h"

# define TRUE		1
# define FALSE		0
# define SUCCESS	0
# define FAIL		-1

# ifndef DELAY
#  define DELAY		1000
# endif

typedef pthread_mutex_t			t_mutex;
typedef pthread_t				t_pthread;
typedef unsigned long long int	t_microsec;

typedef struct s_died
{
	t_mutex		mutex;
	int			index;
	t_microsec	time;
}	t_died;

typedef struct s_time
{
	t_microsec	init;
	int			to_die;
	int			to_eat;
	int			to_sleep;
}	t_time;

typedef struct s_param
{
	int		number_of_philo;
	int		must_eat;
	t_died	died;
	t_time	time;
}	t_param;

typedef struct s_hand
{
	t_mutex	*left;
	t_mutex	*right;
}	t_hand;

typedef struct s_philo
{
	int			index;
	int			meal_qtd;
	t_microsec	last_meal;
	t_hand		hand;
	t_pthread	thread;
	t_param		*param;
}	t_philo;

int			parse_input(int argc, char **argv, t_param *param);
int			initialize_structures(t_philo ***philos, t_mutex ***forks,
				t_param *param, int size);
int			create_philos(t_philo ***philos, t_mutex **forks,
				t_param *param, int size);
int			start_routines(t_philo **philos, t_microsec *init);
int			eating(t_philo *philo);
void		create_control_thread(t_philo *philo);
void		*routine(void *arg);
int			someone_died(t_param *param);
int			no_one_died(t_param *param);
int			already_ate_enough(t_philo *philo);
int			not_ate_enough(t_philo *philo);
void		print(char *message, t_philo *philo);
void		sleeep_ms(int time);
t_microsec	get_time(void);
int			delta_time(t_microsec ini, t_microsec now);
void		free_structures(t_philo	**philos, t_mutex **forks);

#endif
