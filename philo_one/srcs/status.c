/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:34:00 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/23 13:56:33 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		is_everyone_fed(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo[0].global->nb_philo)
	{
		if (philo[i].nb_meal != philo[i].global->must_eat)
			return (0);
	}
	return (1);
}

void	*is_anyone_dead_or_fed(void *pdata)
{
	t_philo			*philo;
	int				i;
	struct timeval	curtime;
	int				timestamp;

	i = -1;
	philo = pdata;
	while (philo[0].global->dead == 0)
	{
		if (is_everyone_fed(philo))
			philo[0].global->dead = 1;
		gettimeofday(&curtime, NULL);
		while (++i < philo[0].global->nb_philo && philo[0].global->dead == 0)
		{
			timestamp = (curtime.tv_sec * 1000 + curtime.tv_usec / 1000) -
		(philo[i].last_eat.tv_sec * 1000 + philo[i].last_eat.tv_usec / 1000);
			if (timestamp > philo[0].global->ttd)
			{
				philo[0].global->dead = 1;
				write_status(&philo[i], RIP);
			}
		}
		i = -1;
	}
	return (0);
}

void	write_status(t_philo *philo, int status)
{
	struct timeval	curtime;
	int				timestamp;

	gettimeofday(&curtime, NULL);
	timestamp = (curtime.tv_sec * 1000 + curtime.tv_usec / 1000) -
		(philo->global->start.tv_sec * 1000 + philo->global->start.tv_usec
			/ 1000);
	if (status == FORK && philo->global->dead == 0)
		printf("%d %d has taken a fork\n", timestamp, philo->number + 1);
	if (status == EAT && philo->global->dead == 0)
		printf("%d %d is eating\n", timestamp, philo->number + 1);
	if (status == SLEEP && philo->global->dead == 0)
		printf("%d %d is sleeping\n", timestamp, philo->number + 1);
	if (status == THINK && philo->global->dead == 0)
		printf("%d %d is thinking\n", timestamp, philo->number + 1);
	if (status == RIP)
		printf("%d %d died\n", timestamp, philo->number + 1);
}

void	meal_time(t_philo *phi)
{
	if (phi->global->myfork[(phi->number + 1) % phi->global->nb_philo])
	{
		pthread_mutex_lock(&phi->global->forks[phi->lfork]);
		phi->global->myfork[phi->number] = 0;
		write_status(phi, FORK);
		pthread_mutex_lock(&phi->global->forks[phi->rfork]);
		phi->global->myfork[(phi->number + 1) % phi->global->nb_philo] = 0;
		write_status(phi, FORK);
		write_status(phi, EAT);
		gettimeofday(&phi->last_eat, NULL);
		phi->nb_meal++;
		nap_time(phi, EAT);
		write_status(phi, SLEEP);
		pthread_mutex_unlock(&phi->global->forks[phi->lfork]);
		phi->global->myfork[phi->number] = 1;
		pthread_mutex_unlock(&phi->global->forks[phi->rfork]);
		phi->global->myfork[(phi->number + 1) % phi->global->nb_philo] = 1;
		nap_time(phi, SLEEP);
	}
}
