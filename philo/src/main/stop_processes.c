#include "philo.h"

void	stop_processes(t_data *data)
{
	int 	i;
	int 	nb_philos;
	t_philo	*philos;

	i = 0;
	nb_philos = get_nb_philos(data);
	philos = data->philos;
	while (i < nb_philos)
	{
		set_philo_state(&philos[i], DEAD);
		i++;
	}
}