#include "philo.h"

void	update_number_meals_had(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_meals_had);
	philo->meals_had++;
	pthread_mutex_unlock(&philo->mut_meals_had);
}