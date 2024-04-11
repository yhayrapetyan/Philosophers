#include "philo.h"

//int	get_nb_philos(t_data *data)
//{
//	int	nb_philos;
//
//	pthread_mutex_lock(&data->mut_nb_philos);
//	nb_philos = data->nb_philos;
//	pthread_mutex_unlock(&data->mut_nb_philos);
//	return (nb_philos);
//}

void	create_threads(t_data *data)
{
	int i;

	i = 0;
	data->start_time = get_time();
	if (pthread_create(&data->alive_monit, NULL, &alive_monitoring, data))
			return ;
	if (data->nb_meals != -1 && pthread_create(&data->full_monit, NULL, &full_monitoring, data))
		return ;
	while (i < data->nb_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL, &routine, &data->philos[i])) {
			return ;
		}
		i++;
	}
}

void	join_threads(t_data *data)
{
	int i;

	i = 0;
	if (pthread_join(data->alive_monit, NULL))
		return ;
	if (data->nb_meals != -1 && pthread_join(data->full_monit, NULL))
		return ;
	while (i < data->nb_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return ;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_input(ac, av) != 0)
		return (print_instructions());
	init_data(&data, ac, av);
	init_philos(&data);
	init_forks(&data);
	create_threads(&data);
	join_threads(&data);
	clean_data(&data);
	return (0);
}