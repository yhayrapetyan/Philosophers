/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:43:20 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/05/04 17:14:47 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	philo_is_full(t_data *data)
{
	if (data->nb_meals < 0)
		return (0);
	if (data->nb_meals <= data->philo.nb_meals_had)
		return (1);
	return (0);
}

static void	simulation(t_data *data)
{
	update_last_meal_time(data);
	while (1)
	{
		sem_wait(data->sem_forks);
		print_message(data, TAKE_FORKS);
		sem_wait(data->sem_forks);
		print_message(data, TAKE_FORKS);
		print_message(data, EAT);
		ft_usleep(data->eat_time);
		sem_post(data->sem_forks);
		sem_post(data->sem_forks);
		sem_wait(data->sem_data);
		data->philo.nb_meals_had++;
		sem_post(data->sem_data);
		if (philo_is_full(data))
		{
			set_philo_state(data, FULL);
			break ;
		}
		print_message(data, SLEEP);
		update_last_meal_time(data);
		ft_usleep(data->sleep_time);
		print_message(data, THINK);
	}
}

int	routine(t_data *data, int id)
{

	init_philo(data, id);
	if (pthread_create(&data->monitor, NULL, &monitoring, data))
	{
		clean_data(data);
		ft_error("Thread create failed\n", 19);
	}
	simulation(data);
	if (pthread_join(data->monitor, NULL))
	{
		clean_data(data);
		ft_error("Thread join failed\n", 19);
	}
	sem_close(data->philo.sem_philo);
	sem_unlink(data->philo_id);
	free(data->philo_id);
	return (0);
}
