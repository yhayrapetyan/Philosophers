#include "philo_bonus.h"

static int	init_semaphores(t_data *data)
{
	sem_unlink("/death");
	sem_unlink("/forks");
	sem_unlink("/print");
	data->sem_forks = sem_open("/forks", O_CREAT, 0644, data->nb_philos);
	data->sem_print = sem_open("/print", O_CREAT, 0644, 1);
	if (data->sem_forks == SEM_FAILED)
		return (printf("SEM FAILED\n"));
	if (data->sem_print == SEM_FAILED)
		return (printf("SEM FAILED\n"));
	sem_unlink("/forks");
	sem_unlink("/print");
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	data->nb_philos = ft_atoi(argv[1]);
	data->die_time = (u_int64_t) ft_atoi(argv[2]);
	data->eat_time = (u_int64_t) ft_atoi(argv[3]);
	data->sleep_time = (u_int64_t) ft_atoi(argv[4]);
	data->nb_meals = -1;
	if (argc == 6)
		data->nb_meals = ft_atoi(argv[5]);
	data->philo.data = data;
	data->philo.nb_meals_had = 0;
	data->philo.state = START;
	return (init_semaphores(data));
}