/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:47:47 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/17 14:15:30 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define RIP 4
int					check_args(int ac, char **av);
void				print_str(char *str);
int					ft_atoi(const char *str);
typedef struct		s_glo
{
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				must_eat;
	pthread_mutex_t	*forks;
	int				*myfork;
	struct timeval	start;
	pthread_mutex_t	death;
	int				dead;
}					t_glo;

typedef struct		s_philo
{
	int				number;
	int				lfork;
	int				rfork;
	struct timeval	last_eat;
	int				nb_meal;
	t_glo			*global;
}					t_philo;

t_glo				*parse_arg(int ac, char **av);
pthread_t			*start_threads(t_glo *args);
t_philo				init_philo(t_glo *args, int number);
void				*start_routine(void *pdata);
void				init_mutexes(t_glo *args);
void				write_status(t_philo *philo, int status);
void				meal_time(t_philo *phi);
int					is_dead(t_philo *philo);
#endif
