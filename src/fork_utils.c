#include "philo.h"

void	drop_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
}

void	drop_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
}

void	drop_forks(t_philo *philo)
{
	drop_right_fork(philo);
	drop_left_fork(philo);
}

int	take_left_fork(t_philo *philo)
{
//	if (philo_died(philo) || get_philo_state(philo) == DEAD)
//		return (1);
	pthread_mutex_lock(philo->l_fork);
//	print_msg(philo->data, philo->id, TAKE_FORKS);
	printf("take left_fork\n");
	return (0);
}

int	take_right_fork(t_philo *philo)
{
//	if (philo_died(philo) || get_philo_state(philo) == DEAD)
//		return (1);
	pthread_mutex_lock(philo->r_fork);
//	print_msg(philo->data, philo->id, TAKE_FORKS);
	printf("take right_fork\n");
	return (0);
}