#include "philo.h"

int can_iterate(t_data *data)
{
	int can_iterate;

	pthread_mutex_lock(&data->mut_iteration);
	can_iterate = data->can_iterate;
	pthread_mutex_unlock(&data->mut_iteration);
	return (can_iterate);
}