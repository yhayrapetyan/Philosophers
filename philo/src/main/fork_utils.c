/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:51:36 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:51:42 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	handle_1_philo(t_philo *philo)
{
	take_left_fork(philo);
	ft_usleep(get_die_time(philo->data));
	set_philo_state(philo, DEAD);
	pthread_mutex_unlock(philo->l_fork);
	return (1);
}

int	take_forks(t_philo *philo)
{
	if (get_nb_philos(philo->data) == 1)
		return (handle_1_philo(philo));
	if (philo->id % 2 == 0)
	{
		if (take_right_fork(philo) != 0)
			return (1);
		if (take_left_fork(philo) != 0)
		{
			pthread_mutex_unlock(philo->r_fork);
			return (1);
		}
	}
	else
	{
		if (take_left_fork(philo) != 0)
			return (1);
		if (take_right_fork(philo) != 0)
		{
			pthread_mutex_unlock(philo->l_fork);
			return (1);
		}
	}
	return (0);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

int	take_left_fork(t_philo *philo)
{
//	if (philo_died(philo) || get_philo_state(philo) == DEAD)
//		return (1);
	pthread_mutex_lock(philo->l_fork);
	print_message(philo->data, philo->id, TAKE_FORKS);
	return (0);
}

int	take_right_fork(t_philo *philo)
{
//	if (philo_died(philo) || get_philo_state(philo) == DEAD)
//		return (1);
	pthread_mutex_lock(philo->r_fork);
	print_message(philo->data, philo->id, TAKE_FORKS);
	return (0);
}
