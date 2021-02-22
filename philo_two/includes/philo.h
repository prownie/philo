/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:47:47 by rpichon           #+#    #+#             */
/*   Updated: 2021/02/22 16:12:07 by root             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
#include <semaphore.h>

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
	sem_t			semaphore;
	int				*myfork;
	struct timeval	start;
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
int					start_threads(t_glo *args);
t_philo				init_philo(t_glo *args, int number);
void				*start_routine(void *pdata);
int					init_semaphore(t_glo *args);
void				write_status(t_philo *philo, int status);
void				meal_time(t_philo *phi);
void				nap_time(t_philo *philo, int status);
int					exit_properly(t_glo *args);
void				*is_anyone_dead_or_fed(void *pdata);
int					is_everyone_fed(t_philo *philo);
#endif
