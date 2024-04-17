#include "philo.h"

int think(t_philo *philo)
{
	set_philo_state(philo, THINKING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_message(philo->data, philo->id, THINK);
//	ft_usleep(1);
	return (0);
}