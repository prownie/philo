/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:34:00 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/16 17:41:52 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int			main(int ac, char **av)
{
	t_glo		args;
	pthread_t	*threads;

	if (check_args(ac, av))
		return (1);
	args = parse_arg(ac, av);
	threads = start_threads(args, threads);
}

void		*start_routine(void *pdata)
{
	t_philo *philo;

	philo = pdata;
	while (philo->global->dead == 0)
	{
		meal_time(philo);
		printf("HEHOOOO\n");
	}
	return (0);
}

pthread_t	*start_threads(t_glo args, pthread_t *threads)
{
	t_philo		philo;
	int			i;

	i = -1;
	init_mutexes(&args);
	if (!(threads = malloc(sizeof(threads) * args.nb_philo)))
		return (0);/*NEED TO FREE EVERYTHING*/
	while (++i < args.nb_philo)
	{
		philo = init_philo(&args, i);
		pthread_create(&threads[i], NULL, start_routine, &philo);
		usleep(10);
	}
	return (threads);
}
