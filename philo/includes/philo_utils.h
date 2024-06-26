/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:47:06 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:47:08 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_UTILS_H
# define PHILO_UTILS_H

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define RESET_COLOR "\033[0m"
# define GREEN "\033[1;32m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>

# define TAKE_FORKS "has taken a fork"
# define TAKE_RFORK "has taken a right fork"
# define TAKE_LFORK "has taken a left fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	START = 5,
}	t_state;

typedef struct s_philo
{
	int				id;
	int				meals_had;
	struct s_data	*data;
	t_state			state;
	u_int64_t		last_eat_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	mut_philo;
}	t_philo;

typedef struct s_data
{
	int					nb_philos;
	int					nb_meals;
	int					full_p;
	u_int64_t			eat_time;
	u_int64_t			die_time;
	u_int64_t			sleep_time;
	u_int64_t			start_time;
	pthread_mutex_t		mut_iteration;
	pthread_mutex_t		mut_print;
	pthread_mutex_t		mut_getter;
	pthread_mutex_t		*forks;
	pthread_t			*philo_ths;
	t_philo				*philos;
}	t_data;

#endif
