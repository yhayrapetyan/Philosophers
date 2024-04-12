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
//		pthread_mutex_lock(&philos->mut_write);
		if (data->can_iterate && philo_died(&philos[i]))
		{
//			pthread_mutex_lock(&data->mut_iteration);
//			pthread_mutex_lock(&philos->mut_write);
			data->can_print = 0;
			data->can_iterate = 0;
			stop_processes(data);
			data->can_print = 1;
			printf("%lu %d %s\n",  get_time() - data->start_time, i + 1, DIED);
//			print_message(data, philos[i].id, DIED);
//			i = 0;
//			while (i < data->nb_philos)
//			{
//				printf("philo[%d] state = %d\n", i, philos[i].state);
//				i++;
//			}
//			exit(0);
			pthread_mutex_unlock(&data->mut_iteration);
//			pthread_mutex_unlock(&philos->mut_write);
			break ;
		}
//		pthread_mutex_unlock(&philos->mut_write);
		pthread_mutex_unlock(&data->mut_iteration);
		if (i == data->nb_philos -1)
			i = 0;
		i++;
		usleep(500);
	}
	return (NULL);
}

void	*full_monitoring(void *data_p)
{
	(void)data_p;
	printf("full monitoring\n");
	return (NULL);
}