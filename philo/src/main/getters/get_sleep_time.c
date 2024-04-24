/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sleep_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:50:14 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:50:16 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	get_sleep_time(t_data *data)
{
	u_int64_t	sleep_time;

	pthread_mutex_lock(&data->mut_getter);
	sleep_time = data->sleep_time;
	pthread_mutex_unlock(&data->mut_getter);
	return (sleep_time);
}
