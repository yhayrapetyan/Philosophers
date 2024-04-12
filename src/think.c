#include "philo.h"

int think(t_philo *philo)
{
	set_philo_state(philo, THINKING);
	if (philo->state == DEAD)
		return (1);
	print_message(philo->data, philo->id, THINK);
	return (0);
}