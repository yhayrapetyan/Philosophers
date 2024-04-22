#include "philo_bonus.h"

uint64_t	get_last_eat_time(t_data *data)
{
	uint64_t	time;

	sem_wait(data->philo.sem_philo);
	time = data->philo.last_eat_time;
	sem_post(data->philo.sem_philo);
	return (time);
}