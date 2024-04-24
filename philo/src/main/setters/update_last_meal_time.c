/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_last_meal_time.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:50:56 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:50:58 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_philo);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->mut_philo);
}
