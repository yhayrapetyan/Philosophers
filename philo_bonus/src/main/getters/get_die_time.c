/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_die_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:32:36 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 16:32:36 by yuhayrap         ###   ########.fr       */
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
