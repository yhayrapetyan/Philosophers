#include "philo.h"

int philo_sleep(t_philo *philo)
{
	set_philo_state(philo, SLEEPING);
	if (philo->state == DEAD) {
		return (1);
	}
	print_message(philo->data, philo->id, SLEEP);
	ft_usleep(philo->data->sleep_time);
	return (0);
}