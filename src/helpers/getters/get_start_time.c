#include "philo.h"

uint64_t	get_start_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mut_start_t);
	time = data->start_time;
	pthread_mutex_unlock(&data->mut_start_t);
	return (time);
}