#include "philo.h"

u_int64_t	get_eat_time(t_data *data)
{
	u_int64_t	eat_time;

	pthread_mutex_lock(&data->mut_eat_time);
	eat_time = data->eat_time;
	pthread_mutex_unlock(&data->mut_eat_time);
	return (eat_time);
}