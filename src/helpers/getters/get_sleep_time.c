#include "philo.h"

u_int64_t	get_sleep_time(t_data *data)
{
	u_int64_t	sleep_time;

	pthread_mutex_lock(&data->mut_sleep_time);
	sleep_time = data->sleep_time;
	pthread_mutex_unlock(&data->mut_sleep_time);
	return (sleep_time);
}