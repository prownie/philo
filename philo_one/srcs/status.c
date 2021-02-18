/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:34:00 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/17 16:41:22 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		is_dead(t_philo *philo)
{
	struct timeval	curtime;

	gettimeofday(&curtime, NULL);
	if (curtime.tv_usec - philo->last_eat.tv_usec > philo->global->ttd)
	{
		pthread_mutex_lock(&philo->global->death);
		if (philo->global->dead == 0)
			write_status(philo, RIP);
		philo->global->dead = 1;
		pthread_mutex_unlock(&philo->global->death);
		return (1);
	}
	return (0);
}

void	write_status(t_philo *philo, int status)
{
	struct timeval	curtime;
	int				timestamp;

	gettimeofday(&curtime, NULL);
	timestamp = (curtime.tv_sec * 1000000 + curtime.tv_usec) -
		(philo->global->start.tv_sec * 1000000 + philo->global->start.tv_usec);
	printf("curtime usec = %ld\n", curtime.tv_usec);
	if (status == 0)
		printf("%d %d has taken a fork\n", timestamp, philo->number);
	if (status == 5)
		printf("%d %d has taken his fork\n", timestamp, philo->number);
	if (status == 1)
		printf("%d %d is eating\n", timestamp, philo->number);
	if (status == 2)
		printf("%d %d is sleeping\n", timestamp, philo->number);
	if (status == 3)
		printf("%d %d is thinking\n", timestamp, philo->number);
	if (status == 4)
		printf("%d %d die\n", timestamp, philo->number);
}

void	meal_time(t_philo *phi)
{
	if (phi->global->myfork[(phi->number + 1) % phi->global->nb_philo])
	{
		pthread_mutex_lock(&phi->global->forks[phi->lfork]);
		phi->global->myfork[phi->number] = 0;
		write_status(phi, 5);
		pthread_mutex_lock(&phi->global->forks[phi->rfork]);
		phi->global->myfork[(phi->number + 1) % phi->global->nb_philo] = 0;
		write_status(phi, FORK);
		write_status(phi, EAT);
		gettimeofday(&phi->last_eat, NULL);
		usleep(phi->global->tte);
		pthread_mutex_unlock(&phi->global->forks[phi->lfork]);
		phi->global->myfork[phi->number] = 1;
		pthread_mutex_unlock(&phi->global->forks[phi->rfork]);
		phi->global->myfork[(phi->number + 1) % phi->global->nb_philo] = 1;
		write_status(phi, SLEEP);
		usleep(phi->global->tts);
	}
}
