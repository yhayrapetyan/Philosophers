#include "philo_bonus.h"

uint64_t	get_die_time(t_data *data)
{
	uint64_t	time;

	sem_wait(data->sem_data);
	time = data->die_time;
	sem_post(data->sem_data);
	return (time);
}