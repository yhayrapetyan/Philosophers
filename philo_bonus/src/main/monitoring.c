/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:41:50 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/05/04 18:25:13 by yuhayrap         ###   ########.fr       */
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
			sem_close(data->philo.sem_philo);
			sem_unlink(data->philo_id);
			free(data->philo_id);
			clean_data(data);
			exit(1);
		}
		usleep(1000);
	}
	return (NULL);
}
