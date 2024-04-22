/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_eat_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:49:40 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:49:42 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_last_eat_time(t_philo *philo)
{
	uint64_t	last_eat_time;

	pthread_mutex_lock(&philo->mut_last_eat_time);
	last_eat_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->mut_last_eat_time);
	return (last_eat_time);
}
