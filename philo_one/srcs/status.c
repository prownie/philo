/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:34:00 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/16 17:42:59 by rpichon          ###   ########lyon.fr   */
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

	gettimeofday(&curtime, NULL);
	if (status == 0)
		printf("%d %d has taken a fork\n", (curtime.tv_usec \
			- philo->global->start.tv_usec) / 1000, philo->number);
	if (status == 5)
		printf("%d %d has taken his fork\n", (curtime.tv_usec \
			- philo->global->start.tv_usec) / 1000, philo->number);
	if (status == 1)
		printf("%d %d is eating\n", (curtime.tv_usec \
			- philo->global->start.tv_usec) / 1000, philo->number);
	if (status == 2)
		printf("%d %d is sleeping\n", (curtime.tv_usec \
			- philo->global->start.tv_usec) / 1000, philo->number);
	if (status == 3)
		printf("%d %d is thinking\n", (curtime.tv_usec \
			- philo->global->start.tv_usec) / 1000, philo->number);
	if (status == 4)
		printf("%d %d die\n", (curtime.tv_usec \
			- philo->global->start.tv_usec) / 1000, philo->number);
}

void		meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->forks[philo->lfork]);
	write_status(philo, FORK);
	printf("HEHOOOO\n");
	pthread_mutex_lock(&philo->global->forks[philo->rfork]);
	printf("HEHAAAAA\n");
	write_status(philo, FORK);
	write_status(philo, EAT);
	printf("HEHIIIII\n");
	gettimeofday(&philo->last_eat, NULL);
	usleep(10);
	//usleep(philo->global->tte);
	pthread_mutex_unlock(&philo->global->forks[philo->lfork]);
	pthread_mutex_unlock(&philo->global->forks[philo->rfork]);
	printf("HEHUUUUU\n");
}
