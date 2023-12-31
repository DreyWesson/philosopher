/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:44:36 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/22 19:43:41 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

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

typedef struct s_time
{
	t_microsec init;
	t_microsec to_die;
	t_microsec to_eat;
	t_microsec to_sleep;
	t_microsec	start_time;
}	t_time;

typedef struct s_param
{
	t_died				died;
	t_time				time;
}						t_param;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				chow;
	int				status;
	int				eating;
	uint64_t		time_to_die;
	t_mutex	lock;
	t_hand hand;
	// t_mutex	*r_fork;
	// t_mutex	*l_fork;
}	t_philo;

typedef struct s_data
{
	int			philo_num;
	t_time		time;
	int			min_meals;
	int				dead;
	int				done;
	t_philo			*philos;
	pthread_t		*tid;
	t_mutex	*forks;
	t_mutex	lock;
	t_mutex	write;
}				t_data;

typedef enum e_args
{
	PHILO_NUM = 1,
	DEATH_TIME = 2,
	EAT_TIME = 3,
	SLEEP_TIME = 4,
	MEAL_NUM = 5

}				t_args;
/**
 * UTILS FUNCTIONS
 */ 
int				ft_error(char *message);
int				is_digit(char *str);
int				ft_atoi(const char *str);
/**
* HELPER FUNCTIONS
*/  
int				validator(int argc, char **argv);
int	validate_value(long val, t_args type);
/**
* INIT FUNCTIONS
*/  
int	init_data(char **argv, t_data *data);
int set_args(char **argv, t_data *data);
int	set_memory(t_data *data);

int	init_thread(t_data *data);
void	*monitor(void *data_pointer);
t_microsec	get_time(void);
void	*routine(void *philo_pointer);
void	*supervisor(void *philo_pointer);
int	ft_strcmp(char *s1, char *s2);
int	ft_sleep(useconds_t time);
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
void	eat(t_philo *philo);
void	messages(char *str, t_philo *philo);

void	ft_exit(t_data *data);
void	clear_data(t_data	*data);


#endif