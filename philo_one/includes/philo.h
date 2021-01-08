/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:47:47 by rpichon           #+#    #+#             */
/*   Updated: 2021/01/08 18:19:18 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

int				check_args(int ac, char **av);
void			print_str(char *str);
int				ft_atoi(const char *str);

typedef struct	s_arg
{
	int		nb_philo;
	int		ttd;
	int		tte;
	int		tts;
	int		must_eat;
}				t_arg;
t_arg			parse_arg(int ac, char **av);
int				philosophers(t_arg args);
#endif
