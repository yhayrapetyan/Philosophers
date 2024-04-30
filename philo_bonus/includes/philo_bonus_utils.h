/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:32:17 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 16:32:17 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_UTILS_H
# define PHILO_BONUS_UTILS_H

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define RESET_COLOR "\033[0m"
# define GREEN "\033[1;32m"

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>
# include <semaphore.h>

# include <sys/wait.h>
# include <fcntl.h>

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_philo_state
{
	EATING,
	DEAD,
	FULL,
	START,
	FINISH,
	SLEEPING
}	t_state;

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				nb_meals_had;
	struct s_data	*data;
	t_state			state;
	u_int64_t		last_eat_time;
	sem_t			*sem_philo;
}	t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	u_int64_t		eat_time;
	u_int64_t		die_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	sem_t			*sem_forks;
	sem_t			*sem_print;
	sem_t			*sem_data;
	sem_t			*sem_death;
	pthread_t		monitor;
	t_philo			philo;
}	t_data;

#endif
