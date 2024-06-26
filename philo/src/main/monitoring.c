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
			stop_processes(data);
			pthread_mutex_lock(&data->mut_print);
			printf("%llu %d %s\n",
				get_time() - get_start_time(data), i + 1, DIED);
			pthread_mutex_unlock(&data->mut_print);
			pthread_mutex_unlock(&data->mut_iteration);
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
	stop_processes(data);
	return (1);
}
