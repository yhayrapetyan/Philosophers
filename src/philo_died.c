#include "philo.h"

int	philo_died(t_philo *philo)
{
	if (get_time() - philo->last_eat_time > philo->data->die_time && \
		philo->state != EATING)
	{
		set_philo_state(philo, DEAD);
		return (1);
	}
	return (0);
}