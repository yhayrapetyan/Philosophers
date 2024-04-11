#include "philo.h"

int think(t_philo *philo)
{
	printf("%d philo think too much and died\n", philo->id);
	set_philo_state(philo, DEAD);
	return (0);
}