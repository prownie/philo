/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:34:00 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/16 17:41:18 by rpichon          ###   ########lyon.fr   */
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
	//printf("philo[%d]. lfork = %d, rfork = %d\n",philo.number,philo.lfork,philo.rfork);
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
		if (pthread_mutex_init(&args->forks[i], NULL) != 0)
			printf("JAI CASSE\n");
	}
	pthread_mutex_init(&args->death, NULL);
}
