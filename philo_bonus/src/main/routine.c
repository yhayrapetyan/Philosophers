/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:43:20 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 17:45:05 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	simulation(t_data *data)
{
	while (!someone_died())
	{
		if (eat(data) || should_stop(get_philo_state(data)))
			break ;
		if (philo_sleep(data) || should_stop(get_philo_state(data)))
			break ;
		if (think(data) || should_stop(get_philo_state(data)))
			break ;
	}
}

int	routine(t_data *data, int id)
{
	char	*philo_id;

	philo_id = init_philo(data, id);
	if (data->philo.id % 2 == 0)
		ft_usleep(data->eat_time);
	if (pthread_create(&data->monitor, NULL, &alive_monitoring, data))
	{
		clean_data(data, 0);
		ft_error("Thread create failed\n", 19);
	}
	simulation(data);
	if (pthread_join(data->monitor, NULL))
	{
		clean_data(data, 1);
		ft_error("Thread join failed\n", 19);
	}
	sem_close(data->philo.sem_philo);
	sem_unlink(philo_id);
	free(philo_id);
	return (0);
}
