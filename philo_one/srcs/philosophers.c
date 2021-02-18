/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:34:00 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/18 16:25:26 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int			main(int ac, char **av)
{
	t_glo		*args;

	if (check_args(ac, av))
		return (1);
	args = parse_arg(ac, av);
	if (!args)
		return (printf("Erreur malloc myfork\n"));
	start_threads(args);
}

void		*start_routine(void *pdata)
{
	t_philo *philo;

	philo = pdata;
	while (philo->global->dead == 0)
	{
		meal_time(philo);
	}
	return (0);
}

int			start_threads(t_glo *args)
{
	t_philo		philo[args->nb_philo];
	int			i;
	pthread_t	threads[args->nb_philo];
	i = -1;

	init_mutexes(args);
	gettimeofday(&args->start, NULL);
	while (++i < args->nb_philo)
	{
		philo[i] = init_philo(args, i);
		pthread_create(&threads[i], NULL, start_routine, &philo[i]);
		usleep(10);
	}
	for (int j = 0; j < args->nb_philo; j++)
		pthread_join(threads[j], NULL);
	return (1);
}
