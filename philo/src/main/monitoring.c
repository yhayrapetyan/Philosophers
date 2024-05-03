/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:51:55 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:51:57 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	notify_philo_died(t_data *data, int id)
{
	data->can_print = 0;
	data->can_iterate = 0;
	stop_processes(data);
//	data->can_print = 1;
	pthread_mutex_lock(&data->mut_print);
	printf("❌ %lu %d %s\n", get_time() - get_start_time(data), id, DIED);
	pthread_mutex_unlock(&data->mut_print);
	pthread_mutex_unlock(&data->mut_iteration);
}

int	alive_monitoring(t_data *data)
{
	int			i;
	int			nb_philos;
	t_philo		*philos;

	philos = (t_philo *)data->philos;
	nb_philos = get_nb_philos(data);
	i = 0;
	while (i < nb_philos)
	{
		pthread_mutex_lock(&data->mut_iteration);
		if (get_time() - philos[i].last_eat_time > data->die_time)
		{
			notify_philo_died(data, i + 1);
			return (1);
		}
		pthread_mutex_unlock(&data->mut_iteration);
		i++;
	}
	return (0);
}

static int	is_philo_full(t_data *data, t_philo *philo)
{
	int	nb_meals_philo_had;

	pthread_mutex_lock(&philo->mut_philo);
	nb_meals_philo_had = philo->meals_had;
	pthread_mutex_unlock(&philo->mut_philo);
	if (nb_meals_philo_had >= get_nb_meals(data))
		return (1);
	return (0);
}

int	full_monitoring(t_data *data)
{
	int		i;
	int		nb_philos;

	i = 0;
	if (data->nb_meals == -1)
		return (0);
	nb_philos = get_nb_philos(data);
	while (i < nb_philos)
	{
		if (!is_philo_full(data, &data->philos[i]))
			return (0);
		i++;
	}
	if (can_iterate(data))
	{
		pthread_mutex_lock(&data->mut_iteration);
		data->can_iterate = 0;
		pthread_mutex_unlock(&data->mut_iteration);
		stop_processes(data);
		return (1);
	}
	return (0);
}
