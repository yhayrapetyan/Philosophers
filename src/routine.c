#include "philo.h"

void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time - 10);
	while (get_philo_state(philo) != DEAD)
	{
		eat(philo);
		if (get_philo_state(philo) == DEAD)
			break ;
		philo_sleep(philo);
		if (get_philo_state(philo) == DEAD)
			break ;
		think(philo);
	}
	return (NULL);
}