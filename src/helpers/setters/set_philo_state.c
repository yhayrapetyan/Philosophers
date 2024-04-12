#include "philo.h"

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mut_write);
	philo->state = state;
//	if (philo->state != DEAD)
//		philo->state = state;
	pthread_mutex_unlock(&philo->mut_write);
}