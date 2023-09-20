/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:37:24 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/20 20:54:10 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philo.h"

t_microsec	get_time(void);
void	messages(char *str, t_philo *philo);

void	clear_data(t_data	*data)
{
	if (data->tid)
		free(data->tid);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	// clear_data(data);
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->hand.right);
	messages("has taken a fork", philo);
	pthread_mutex_lock(philo->hand.left);
	messages("has taken a fork", philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->hand.left);
	pthread_mutex_unlock(philo->hand.right);
	messages("is sleeping", philo);
	ft_usleep(philo->data->time.to_sleep);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = get_time() + philo->data->time.to_die;
	messages("is eating", philo);
	philo->chow++;
	ft_usleep(philo->data->time.to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_forks(philo);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

void	messages(char *str, t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->data->write);
	time = get_time() - philo->data->time.init;
	if (ft_strcmp("died", str) == 0 && philo->data->dead == 0)
	{
		printf("%llu %d %s\n", time, philo->id, str);
		philo->data->dead = 1;
	}
	if (!philo->data->dead)
		printf("%llu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}

void	*supervisor(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
			messages("died", philo);
		if (philo->chow == philo->data->min_meals)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->done++;
			philo->chow++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	philo->time_to_die = philo->data->time.to_die + get_time();
	if (pthread_create(&philo->t1, NULL, &supervisor, (void *)philo))
		return ((void *)1);
	while (philo->data->dead == 0)
	{
		eat(philo);
		messages("is thinking", philo);
	}
	if (pthread_join(philo->t1, NULL))
		return ((void *)1);
	return ((void *)0);
}

t_microsec	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (ft_error("gettimeofday() failed!\n"), 1);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

int single_philo(t_data *data)
{
	data->time.init = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
		return (ft_error("Thread error"), 1);
	pthread_detach(data->tid[0]);
	while (data->dead == 0)
		ft_usleep(0);
	ft_exit(data);
	return (0);
}

int init_thread()
{
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (validator(argc, argv))
		return (1);
	if (!init_data(argv, &data))
		return (2);
	// if (init_thread())
	// {
	// 	if (data.philo_num == 1)
	// 		single_philo(&data);
	// 	return (3);
	// }
	
	printf("%d %llu %llu %llu %d\n", data.philo_num, data.time.to_die,
		data.time.to_eat, data.time.to_sleep, data.min_meals);
	return (0);
}