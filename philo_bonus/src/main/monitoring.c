/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:41:50 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 17:06:34 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	someone_died(void)
{
	sem_t	*death;

	death = sem_open("/death", AT_EACCESS, 0644, 0);
	if (death == SEM_FAILED)
		return (0);
	sem_close(death);
	return (1);
}

static int	philo_died(t_data *data)
{
	if (get_philo_state(data) != EATING
		&& get_time() - get_last_eat_time(data) > get_die_time(data))
		return (1);
	return (0);
}

int	get_id(t_data *data)
{
	int	id;

	sem_wait(data->sem_data);
	id = data->philo.id;
	sem_post(data->sem_data);
	return (id);
}

void	*alive_monitoring(void *data_p)
{
	t_data	*data;

	data = (t_data *)data_p;
	while (should_stop(get_philo_state(data)) == 0)
	{
		if (someone_died())
			return (set_philo_state(data, FINISH), NULL);
		if (philo_died(data))
		{
			sem_wait(data->sem_print);
			if (philo_died(data) && someone_died() == 0)
			{
				set_philo_state(data, DEAD);
				data->sem_death = sem_open("/death", O_CREAT, 0644, 0);
				printf("%llu %d %s\n", get_time() - get_start_time(data),
					get_id(data), DIED);
				sem_post(data->sem_print);
				break ;
			}
			sem_post(data->sem_print);
		}
		usleep(1000);
	}
	return (NULL);
}
