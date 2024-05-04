/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:13:39 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/05/04 19:06:30 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

uint64_t	get_die_time(t_data *data)
{
	uint64_t	time;

	sem_wait(data->sem_data);
	time = data->die_time;
	sem_post(data->sem_data);
	return (time);
}

uint64_t	get_last_eat_time(t_data *data)
{
	uint64_t	time;

	sem_wait(data->sem_data);
	time = data->philo.last_eat_time;
	sem_post(data->sem_data);
	return (time);
}

t_state	get_philo_state(t_data *data)
{
	t_state	state;

	sem_wait(data->philo.sem_philo);
	state = data->philo.state;
	sem_post(data->philo.sem_philo);
	return (state);
}

uint64_t	get_start_time(t_data *data)
{
	uint64_t	time;

	sem_wait(data->sem_data);
	time = data->start_time;
	sem_post(data->sem_data);
	return (time);
}

u_int64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}
