#include "philo_bonus.h"

int	philo_sleep(t_data *data)
{
	set_philo_state(data, SLEEPING);
	if (print_message(data, SLEEP))
		return (1);
	ft_usleep(data->sleep_time);
	return (0);
}