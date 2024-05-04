/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:41:50 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/05/04 17:04:52 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitoring(void *data_p)
{
	t_data	*data;

	data = (t_data *)data_p;
	while (should_stop(get_philo_state(data)) == 0)
	{
		if (get_time() - get_last_eat_time(data) > get_die_time(data) && \
			get_philo_state(data) != FULL)
		{
			sem_wait(data->sem_print);
			printf("%llu %d %s\n", get_time() - get_start_time(data),
				data->philo.id, DIED);
			exit(1);//need to clean
		}
		usleep(1000);
	}
	return (NULL);
}
