#include "philo_bonus.h"

int	drop_forks(t_data *data)
{
	sem_post(data->sem_forks);
	sem_post(data->sem_forks);
	return (0);
}

int	take_forks(t_data *data)
{
	sem_wait(data->sem_forks);
	if (print_message(data, TAKE_FORKS))
	{
		sem_post(data->sem_forks);
		return (1);
	}
	if (data->nb_philos == 1)
		return (1);
	sem_wait(data->sem_forks);
	if (should_stop(get_philo_state(data)))
	{
		drop_forks(data);
		return (1);
	}
	if (print_message(data, TAKE_FORKS))
	{
		drop_forks(data);
		return (1);
	}
	return (0);
}
