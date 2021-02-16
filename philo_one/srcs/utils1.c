/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:58:25 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/16 17:09:09 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		print_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

static int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		sign;
	long	i;

	if (!str)
		return (0);
	sign = 1;
	i = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = -1;
			str++;
		}
		else
			str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + *str - '0';
		str++;
	}
	return (i * sign);
}

t_glo		parse_arg(int ac, char **av)
{
	t_glo	args;

	args.nb_philo = ft_atoi(av[1]);
	args.ttd = ft_atoi(av[2]) * 1000;
	args.tte = ft_atoi(av[3]) * 1000;
	args.tts = ft_atoi(av[4]) * 1000;
	if (ac == 6)
		args.must_eat = ft_atoi(av[5]);
	else
		args.must_eat = 0;
	args.dead = 0;
	return (args);
}
