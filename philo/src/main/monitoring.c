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
	data->can_print = 1;
	pthread_mutex_lock(&data->mut_print);
	printf("%llu %d %s\n", get_time() - get_start_time(data), id, DIED);
	pthread_mutex_unlock(&data->mut_print);
	pthread_mutex_unlock(&data->mut_iteration);
}

void	*alive_monitoring(void *data_p)
{
	int			i;
	int			nb_philos;
	t_data		*data;
	t_philo		*philos;

	data = (t_data *)data_p;
	philos = (t_philo *)data->philos;
	nb_philos = get_nb_philos(data);
	i = 0;
	while (i < nb_philos && can_iterate(data) == 1)
	{
		pthread_mutex_lock(&data->mut_iteration);
		if (data->can_iterate && (philo_died(&philos[i]) || \
			get_philo_state(&philos[i]) == DEAD))
		{
			notify_philo_died(data, i + 1);
			break ;
		}
		pthread_mutex_unlock(&data->mut_iteration);
		if (i == nb_philos - 1)
			i = -1;
		i++;
		// usleep(500);
	}
	return (NULL);
}

static int	is_philo_full(t_data *data, t_philo *philo)
{
	int	nb_meals_philo_had;

	pthread_mutex_lock(&philo->mut_meals_had);
	nb_meals_philo_had = philo->meals_had;
	pthread_mutex_unlock(&philo->mut_meals_had);
	if (nb_meals_philo_had >= get_nb_meals(data))
		return (1);
	return (0);
}

void	*full_monitoring(void *data_p)
{
	int		i;
	t_data	*data;
	int		nb_philos;

	i = 0;
	data = (t_data *)data_p;
	nb_philos = get_nb_philos(data);
	while (i < nb_philos && can_iterate(data))
	{
		usleep(500);
		if (!is_philo_full(data, &data->philos[i]))
			i = -1;
		i++;
	}
	if (can_iterate(data))
	{
		pthread_mutex_lock(&data->mut_iteration);
		data->can_iterate = 0;
		pthread_mutex_unlock(&data->mut_iteration);
		stop_processes(data);
	}
	return (NULL);
}
