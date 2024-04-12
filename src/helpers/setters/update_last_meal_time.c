#include "philo.h"

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_write);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->mut_write);
}