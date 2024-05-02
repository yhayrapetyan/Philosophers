/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:51:31 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:51:33 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	handle_1_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_message(philo->data, philo->id, TAKE_FORKS);
	ft_usleep(get_die_time(philo->data));
	set_philo_state(philo, DEAD);
	pthread_mutex_unlock(philo->l_fork);
	return (1);
}

int	eat(t_philo *philo)
{
	if (get_nb_philos(philo->data) == 1)
		return (handle_1_philo(philo));
	pthread_mutex_lock(philo->r_fork);
	print_message(philo->data, philo->id, TAKE_FORKS);
	pthread_mutex_lock(philo->l_fork);
	print_message(philo->data, philo->id, TAKE_FORKS);
	print_message(philo->data, philo->id, EAT);
	ft_usleep(get_eat_time(philo->data));
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	update_last_meal_time(philo);
	if (philo->meals_had != -1)
		update_number_meals_had(philo);
	return (0);
}
