#include "philo.h"

int can_print(t_data *data)
{
	int can_print;

	pthread_mutex_lock(&data->mut_print);
	can_print = data->can_print;
	pthread_mutex_unlock(&data->mut_print);
	return (can_print);
}