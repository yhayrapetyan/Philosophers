#include "philo.h"

void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time - 10);
	while (philo->state != DEAD)
	{
		if (eat(philo) != 0)
			break ;
		if (philo->state == DEAD)
			break ;
		if (philo_sleep(philo) != 0)
			break ;
		if (philo->state == DEAD)
			break ;
		if (think(philo) != 0)
			break ;
	}
	return (NULL);
}