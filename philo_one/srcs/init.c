/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:34:00 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/22 16:14:28 by root             ###   ########lyon.fr   */
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

int			init_mutexes(t_glo *args)
{
	int		i;

	i = -1;
	if (!(args->forks = malloc(sizeof(args->forks) * args->nb_philo)))
		return(1);
	while (++i < args->nb_philo)
		pthread_mutex_init(&args->forks[i], NULL);
	return (0);
}
