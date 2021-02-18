/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:34:00 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/18 13:56:48 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo		init_philo(t_glo *args, int number)
{
	t_philo	philo;

	philo.number = number;
	philo.lfork = number;
	philo.rfork = (number + 1) % args->nb_philo;
	gettimeofday(&philo.last_eat, NULL);
	philo.nb_meal = 0;
	philo.global = args;
	return (philo);
}

void		init_mutexes(t_glo *args)
{
	int		i;

	i = -1;
	if (!(args->forks = malloc(sizeof(args->forks) * args->nb_philo)))
		exit(0);
	while (++i < args->nb_philo)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		//	printf("JAI CASSE\n");
	}
	pthread_mutex_init(&args->death, NULL);
}
