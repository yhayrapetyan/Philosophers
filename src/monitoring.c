#include "philo.h"

static void	stop_processes(t_data *data)
{
	int 	i;
	t_philo	*philos;

	i = 0;
	philos = data->philos;
	while (i < data->nb_philos)
	{
		set_philo_state(&philos[i], DEAD);
		i++;
	}
}

void	*alive_monitoring(void *data_p)
{
	int 	i;
	t_data	*data;
	t_philo *philos;

	data = (t_data *)data_p;
	philos = (t_philo *)data->philos;
	i = 0;
	while (i < data->nb_philos && data->can_iterate)
	{
		pthread_mutex_lock(&data->mut_iteration);
		if (data->can_iterate && philo_died(&philos[i]))
		{
			data->can_print = 0;
			data->can_iterate = 0;
			stop_processes(data);
			data->can_print = 1;
			printf("%lu %d %s\n",  get_time() - data->start_time, i + 1, DIED);
			pthread_mutex_unlock(&data->mut_iteration);
			break ;
		}
		pthread_mutex_unlock(&data->mut_iteration);
		if (i == data->nb_philos -1)
			i = 0;
		i++;
		usleep(500);
	}
	return (NULL);
}

static int is_philo_full(t_data *data, t_philo *philo)
{
	int	nb_meals_philo_had;

	pthread_mutex_lock(&philo->mut_meals_had);
	nb_meals_philo_had = philo->meals_had;
	pthread_mutex_unlock(&philo->mut_meals_had);
	if (nb_meals_philo_had >= data->nb_meals)
		return (1);
	return (0);
}

void	*full_monitoring(void *data_p)
{
	int 	i;
	t_data	*data;

	i = 0;
	data = (t_data *)data_p;
	while (i < data->nb_philos && data->can_iterate)
	{
		usleep(500);
		if (!is_philo_full(data, &data->philos[i])) {
			i = 0;
		}
		i++;
	}
	if (data->can_iterate)
	{
		pthread_mutex_lock(&data->mut_iteration);
		data->can_iterate = 0;
		pthread_mutex_unlock(&data->mut_iteration);
		stop_processes(data);
	}
	return (NULL);
}