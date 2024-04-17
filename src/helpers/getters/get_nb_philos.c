#include "philo.h"

int get_nb_philos(t_data *data)
{
	int nb;

	pthread_mutex_lock(&data->mut_nb_philos);
	nb = data->nb_philos;
	pthread_mutex_unlock(&data->mut_nb_philos);
	return (nb);
}