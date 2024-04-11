#include "philo.h"

void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
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
	(void)philo;
	fprintf(stderr,"routine\n");
	return (NULL);
}