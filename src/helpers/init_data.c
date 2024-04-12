#include "philo.h"

void	init_forks(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = data->philos;
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	philos[0].l_fork = &data->forks[0];
	philos[0].r_fork = &data->forks[data->nb_philos - 1];
	i = 1;
	while (i < data->nb_philos)
	{
		philos[i].l_fork = &data->forks[i];
		philos[i].r_fork = &data->forks[i - 1];
		i++;
	}
}

void	init_philos(t_data *data)
{
	int			i;
	t_philo		*philos;

	i = 0;
	philos = data->philos;
	while (i < data->nb_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_had = 0;
		philos[i].state = START;
		philos[i].data = data;
		pthread_mutex_init(&philos[i].mut_write, NULL);
//		pthread_mutex_init(&philos[i].mut_state, NULL);
//		pthread_mutex_init(&philos[i].mut_meals_had, NULL);
//		pthread_mutex_init(&philos[i].mut_last_eat_time, NULL);
		update_last_meal_time(&philos[i]);
		i++;
	}
}

static void	allocate_memory(t_data *data)
{
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philos == NULL)
		ft_error("Allocation Fails\n", 17);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->forks == NULL)
	{
		free(data->philos);
		ft_error("Allocation Fails\n", 17);
	}
	data->philo_ths = (pthread_t *)malloc(sizeof(pthread_t) * data->nb_philos);
	if (data->philo_ths == NULL)
	{
		free(data->philos);
		free(data->forks);
		ft_error("Allocation Fails\n", 17);
	}
}

void	init_data(t_data *data, int ac, char **av)
{
	data->nb_philos = ft_atoi(av[1]);
	data->nb_meals = -1;
	data->full_p = 0;
	data->can_print = 1;
	data->eat_time = (u_int64_t)ft_atoi(av[3]);
	data->die_time = (u_int64_t)ft_atoi(av[2]);
	data->sleep_time = (u_int64_t)ft_atoi(av[4]);
	if (ac == 6)
		data->nb_meals = ft_atoi(av[5]);
//	pthread_mutex_init(&data->mut_eat_t, NULL);
//	pthread_mutex_init(&data->mut_sleep_t, NULL);
//	pthread_mutex_init(&data->mut_die_t, NULL);
//	pthread_mutex_init(&data->mut_nb_philos, NULL);
//	pthread_mutex_init(&data->mut_start_t, NULL);
//	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_iteration, NULL);
	allocate_memory(data);
}