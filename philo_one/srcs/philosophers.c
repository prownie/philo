/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:34:00 by rpichon           #+#    #+#             */
/*   Updated: 2021/01/08 18:20:11 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int philosophers(t_arg args)
{
	static pthread_mutex_t forks_mutex = PTHREAD_MUTEX_INITIALIZER;

	int pthread_mutex_init(forks_mutex, const pthread_mutexattr_t *mutexattr);
}

int	main(int ac, char **av)
{
	t_arg args;

	if (check_args(ac, av))
		return (1);
	args = parse_arg(ac, av);
}
