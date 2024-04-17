#include "philo.h"

uint64_t	get_die_time(t_data *data)
{
	uint64_t	die_time;

	pthread_mutex_lock(&data->mut_die_time);
	die_time = data->die_time;
	pthread_mutex_unlock(&data->mut_die_time);
	return (die_time);
}