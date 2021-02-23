/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:58:25 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/22 16:42:36 by root             ###   ########lyon.fr   */
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

t_glo		*parse_arg(int ac, char **av)
{
	t_glo	*args;

	if (!(args = malloc(sizeof(t_glo))))
		return (NULL);
	args->nb_philo = ft_atoi(av[1]);
	args->ttd = ft_atoi(av[2]);
	args->tte = ft_atoi(av[3]);
	args->tts = ft_atoi(av[4]);
	if (ac == 6)
		args->must_eat = ft_atoi(av[5]);
	else
		args->must_eat = -1;
	args->dead = 0;
	if (!(args->myfork = malloc(sizeof(args->myfork) * args->nb_philo)))
		return (NULL);
	return (args);
}

int			exit_properly(t_glo *args)
{
	if (args)
	{
		if (args->forks)
			free(args->forks);
		if (args->myfork)
			free(args->myfork);
		free(args);
	}
	return (1);
}
