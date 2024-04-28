#include "philo_bonus.h"

uint64_t	get_last_eat_time(t_data *data)
{
	uint64_t	time;

	sem_wait(data->sem_data);
	time = data->philo.last_eat_time;
	sem_post(data->sem_data);
	return (time);
}