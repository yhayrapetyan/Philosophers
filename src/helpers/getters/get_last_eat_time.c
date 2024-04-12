#include "philo.h"

uint64_t	get_last_eat_time(t_philo *philo)
{
	uint64_t	last_eat_time;

//	pthread_mutex_lock(&philo->mut_last_eat_time);
	last_eat_time = philo->last_eat_time;
//	pthread_mutex_unlock(&philo->mut_last_eat_time);
	return (last_eat_time);
}