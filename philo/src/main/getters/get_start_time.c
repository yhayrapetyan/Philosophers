/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:50:25 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:50:27 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_start_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mut_getter);
	time = data->start_time;
	pthread_mutex_unlock(&data->mut_getter);
	return (time);
}
