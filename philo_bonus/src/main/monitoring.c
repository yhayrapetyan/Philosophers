#include "philo_bonus.h"

int	someone_died(void)
{
	sem_t	*death;

	death = sem_open("/death", AT_EACCESS, 0);
	if (death == SEM_FAILED)
		return (0);
	sem_close(death);
	return (1);
}

static int	philo_died(t_data *data)
{
	if (get_philo_state(data) != EATING
		&& get_time() - get_last_eat_time(data) > data->die_time)
		return (1);
	return (0);
}

void	*alive_monitoring(void *data_p)
{
	t_data	*data;

	data = (t_data *)data_p;
	while (should_stop(get_philo_state(data)) == 0)
	{
		if (someone_died())
			return (set_philo_state(data, FINISH), NULL);
		if (philo_died(data))
		{
			sem_wait(data->sem_print);
			if (philo_died(data) && someone_died() == 0)
			{
				set_philo_state(data, DEAD);
				sem_open("/death", O_CREAT, 0644, 0);
				printf("%lu %d %s\n", get_time() - data->start_time,
					data->philo.id, DIED);
				sem_post(data->sem_print);
				break ;
			}
			sem_post(data->sem_print);
		}
		usleep(500);
	}
	return (NULL);
}
