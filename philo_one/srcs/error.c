/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:44:34 by rpichon           #+#    #+#             */
/*   Updated: 2021/01/08 17:35:31 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_args(int ac, char **av)
{
	int i;

	i = 0;
	if ((ac < 5 || ac > 6) && ++i)
	{
		print_str("Wrong number of arguments\n");
		return (1);
	}
	if (ft_atoi(av[1]) < 1 && ++i)
		print_str("Bad philo number\n");
	if (ft_atoi(av[2]) < 1 && ++i)
		print_str("Bad time to die value\n");
	if (ft_atoi(av[3]) < 1 && ++i)
		print_str("Bad time to eat value\n");
	if (ft_atoi(av[4]) < 1 && ++i)
		print_str("Bad time to sleep value\n");
	if (ac == 6 && ft_atoi(av[5]) < 1 && ++i)
		print_str("Wrong \"must eat\" value\n");
	if (i)
		return (1);
	return (0);
}
