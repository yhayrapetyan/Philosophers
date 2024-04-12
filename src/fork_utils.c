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
//	printf("SSSS %d philo L__start status = %d\n", philo->id, philo->state);
	if (philo_died(philo) || philo->state == DEAD)
		return (1);
//	printf("MMMM %d philo L__middle status = %d\n", philo->id, philo->state);
	pthread_mutex_lock(philo->l_fork);
	print_message(philo->data, philo->id, TAKE_FORKS);
//	printf("EEEE %d philo L__left status = %d\n", philo->id, philo->state);
	return (0);
}

int	take_right_fork(t_philo *philo)
{
//	printf("SSSS %d philo R__start status = %d\n", philo->id, philo->state);
	if (philo_died(philo) || philo->state == DEAD)
		return (1);
//	printf("MMMM %d philo R__middle status = %d\n", philo->id, philo->state);
	pthread_mutex_lock(philo->r_fork);
	print_message(philo->data, philo->id, TAKE_FORKS);
//	printf("EEEE %d philo R__left status = %d\n", philo->id, philo->state);

	return (0);
}