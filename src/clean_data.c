#include "philo.h"

void	clean_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].mut_meals_had);
		pthread_mutex_destroy(&data->philos[i].mut_last_eat_time);
		i++;
	}
	pthread_mutex_destroy(&data->mut_iteration);
	pthread_mutex_destroy(&data->mut_print);
	free(data->philo_ths);
	free(data->philos);
	free(data->forks);
}