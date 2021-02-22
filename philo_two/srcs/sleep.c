/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:34:00 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/22 16:31:38 by root             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		nap_time(t_philo *philo, int status)
{
	int				sleep;
	struct timeval	start;
	struct timeval	curtime;
	int				i;

	i = 0;
	gettimeofday(&start, NULL);
	if (status == EAT)
		sleep = philo->global->tte;
	else if (status == SLEEP)
		sleep = philo->global->tts;
	printf("sleep = %d\n", sleep);
	while (i < sleep)
	{
		gettimeofday(&curtime, NULL);
		i = (curtime.tv_sec * 1000 + curtime.tv_usec / 1000) -
			(start.tv_sec * 1000 + start.tv_usec / 1000);
	}
}
