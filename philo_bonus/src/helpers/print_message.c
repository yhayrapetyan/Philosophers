#include "philo_bonus.h"

int	print_message(t_data *data, char *message)
{
	sem_wait(data->sem_print);
	if (someone_died())
	{
		sem_post(data->sem_print);
		return (1);
	}
	printf("%llu %d %s\n", get_time() - data->start_time,
		data->philo.id, message);
	sem_post(data->sem_print);
	return (0);
}
