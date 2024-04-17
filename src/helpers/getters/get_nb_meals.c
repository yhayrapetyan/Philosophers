#include "philo.h"

int get_nb_meals(t_data *data)
{
	int nb_meals;

	pthread_mutex_lock(&data->mut_nb_meals);
	nb_meals = data->nb_meals;
	pthread_mutex_unlock(&data->mut_nb_meals);
	return (nb_meals);
}