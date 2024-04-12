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
	while (i < data->nb_philos)
	{
//		pthread_mutex_lock(&data->mut_iteration);
		if (philo_died(&philos[i]) || philos[i].state == DEAD)
		{
//			pthread_mutex_lock(&data->mut_iteration);
			print_message(data, philos[i].id, DIED);
//			data->can_print = 0;
//			pthread_mutex_unlock(&data->mut_iteration);
			stop_processes(data);
			break ;
		}
//		pthread_mutex_unlock(&data->mut_iteration);
		if (i == data->nb_philos -1)
			i = 0;
		i++;
		usleep(1000);
	}
	return (NULL);
}

void	*full_monitoring(void *data_p)
{
	(void)data_p;
	printf("full monitoring\n");
	return (NULL);
}