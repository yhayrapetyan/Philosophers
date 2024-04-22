/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:51:26 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:51:27 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].mut_meals_had);
		pthread_mutex_destroy(&data->philos[i].mut_last_eat_time);
		i++;
	}
	pthread_mutex_destroy(&data->mut_iteration);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_eat_time);
	pthread_mutex_destroy(&data->mut_nb_philos);
	pthread_mutex_destroy(&data->mut_sleep_time);
	pthread_mutex_destroy(&data->mut_die_time);
	pthread_mutex_destroy(&data->mut_start_time);
	pthread_mutex_destroy(&data->mut_nb_meals);
	free(data->philo_ths);
	free(data->philos);
	free(data->forks);
}
