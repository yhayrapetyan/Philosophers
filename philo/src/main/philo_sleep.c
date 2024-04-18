#include "philo.h"

int philo_sleep(t_philo *philo)
{
	if (get_philo_state(philo) == DEAD)
		return (1);
	set_philo_state(philo, SLEEPING);
	print_message(philo->data, philo->id, SLEEP);
	ft_usleep(get_sleep_time(philo->data));
	return (0);
}