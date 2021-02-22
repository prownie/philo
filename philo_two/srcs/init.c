/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:34:00 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/22 16:29:52 by root             ###   ########lyon.fr   */
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

int			init_semaphore(t_glo *args)
{
	if (sem_init(&args->semaphore, 0, args->nb_philo))
		return (1);
	return (0);
}
