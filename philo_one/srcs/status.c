/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:34:00 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/18 16:41:08 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		is_dead(t_philo *philo, struct timeval curtime)
{
	int				timestamp;

	timestamp = (curtime.tv_sec * 1000 + curtime.tv_usec / 1000) -
		(philo->last_eat.tv_sec * 1000 + philo->last_eat.tv_usec / 1000);
	if (timestamp > 400)
		printf("timestamp dans is dead = %d\n",timestamp);
	if (timestamp > philo->global->ttd)
	{
		printf("JE SUIS RENTRE LA DEDANS\n");
		pthread_mutex_lock(&philo->global->death);
		if (philo->global->dead == 0)
		{
			philo->global->dead = 1;
			write_status(philo, RIP);
		}
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
	timestamp = (curtime.tv_sec * 1000 + curtime.tv_usec / 1000) -
		(philo->global->start.tv_sec * 1000 + philo->global->start.tv_usec / 1000);
	if (status == FORK && philo->global->dead == 0)
		printf("%d %d has taken a fork\n", timestamp, philo->number );
	if (status == 5 && philo->global->dead == 0)
		printf("%d %d has taken his fork\n", timestamp, philo->number );
	if (status == EAT && philo->global->dead == 0)
		printf("%d %d is eating\n", timestamp, philo->number );
	if (status == SLEEP && philo->global->dead == 0)
		printf("%d %d is sleeping\n", timestamp, philo->number );
	if (status == THINK && philo->global->dead == 0)
		printf("%d %d is thinking\n", timestamp, philo->number );
	if (status == RIP)
		printf("%d %d died\n", timestamp, philo->number );
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
		nap_time(phi, EAT);
		pthread_mutex_unlock(&phi->global->forks[phi->lfork]);
		phi->global->myfork[phi->number] = 1;
		pthread_mutex_unlock(&phi->global->forks[phi->rfork]);
		phi->global->myfork[(phi->number + 1) % phi->global->nb_philo] = 1;
		write_status(phi, SLEEP);
		nap_time(phi, SLEEP);
		usleep(200000);
	}
}

