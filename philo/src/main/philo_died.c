#include "philo.h"

int	philo_died(t_philo *philo)
{
	if (get_time() - get_last_eat_time(philo) > get_die_time(philo->data) && \
        get_philo_state(philo) != EATING)
	{
		set_philo_state(philo, DEAD);
		return (1);
	}
	return (0);
}