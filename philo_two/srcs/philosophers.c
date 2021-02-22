/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:34:00 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/22 16:15:29 by root             ###   ########lyon.fr   */
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
		return (exit_properly(args));
	if (start_threads(args))
		return (exit_properly(args));
	return (exit_properly(args));
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
	pthread_t	threads[args->nb_philo + 1];

	i = -1;
	if (init_semaphore(args))
		return (1);
	gettimeofday(&args->start, NULL);
	while (++i < args->nb_philo)
	{
		philo[i] = init_philo(args, i);
		pthread_create(&threads[i], NULL, start_routine, &philo[i]);
		usleep(10);
	}
	pthread_create(&threads[i], NULL, is_anyone_dead_or_fed, &philo);
	while (i >= 0)
	{
		pthread_join(threads[i], NULL);
		i--;
	}
	return (0);
}
