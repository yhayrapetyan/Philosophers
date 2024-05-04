/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:21 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:52:23 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*handle_1_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_message(philo->data, philo->id, TAKE_FORKS);
	ft_usleep(get_die_time(philo->data));
	set_philo_state(philo, DEAD);
	pthread_mutex_unlock(philo->l_fork);
	return (NULL);
}

void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	update_last_meal_time(philo);
	if (philo->id % 2 == 0)
		ft_usleep(get_eat_time(philo->data));
	while (get_philo_state(philo) != DEAD)
	{
		if (get_nb_philos(philo->data) == 1)
			return (handle_1_philo(philo));
		eat(philo);
		print_message(philo->data, philo->id, SLEEP);
		ft_usleep(get_sleep_time(philo->data));
		print_message(philo->data, philo->id, THINK);
	}
	return (NULL);
}
