#include "philo_bonus.h"

static int	philo_is_full(t_data *data)
{
	if (data->nb_meals < 0)
		return (0);
	if (data->nb_meals <= data->philo.nb_meals_had)
	{
		set_philo_state(data, FULL);
		return (1);
	}
	return (0);
}

int	eat(t_data *data)
{
	if (take_forks(data))
		return (1);
	update_last_meal_time(data);
	set_philo_state(data, EATING);
	if (print_message(data, EAT))
	{
		drop_forks(data);
		return (1);
	}
	ft_usleep(data->sleep_time);
	drop_forks(data);
	data->philo.nb_meals_had++;
	if (philo_is_full(data))
		return (1);
	return (0);
}
