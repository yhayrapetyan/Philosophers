#include "philo.h"

static int	take_forks(t_philo *philo)
{
	if (philo->data->nb_philos == 1)
		return (1);//need to handle 1 philo
	if (take_right_fork(philo) != 0)
		return (1);
	if (take_left_fork(philo) != 0)
	{
		drop_right_fork(philo);
		return (1);
	}
	return (0);
}

int eat(t_philo *philo)
{
	if (take_forks(philo) != 0)
		return (1);
	drop_left_fork(philo);
	drop_right_fork(philo);
	printf("%d philo is eating\n", philo->id);
	return (0);
}