/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:51:45 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/05/04 13:23:47 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		pthread_mutex_init(&philos[i].mut_philo, NULL);
		update_last_meal_time(&philos[i]);
		i++;
	}
}

static int	allocate_memory(t_data *data)
{
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philos == NULL)
		return (ft_error("Allocation Fails\n"));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->forks == NULL)
	{
		free(data->philos);
		return (ft_error("Allocation Fails\n"));
	}
	data->philo_ths = (pthread_t *)malloc(sizeof(pthread_t) * data->nb_philos);
	if (data->philo_ths == NULL)
	{
		free(data->philos);
		free(data->forks);
		return (ft_error("Allocation Fails\n"));
	}
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	data->nb_philos = ft_atoi(av[1]);
	data->nb_meals = -1;
	data->full_p = 0;
	data->eat_time = (u_int64_t)ft_atoi(av[3]);
	data->die_time = (u_int64_t)ft_atoi(av[2]);
	data->sleep_time = (u_int64_t)ft_atoi(av[4]);
	if (ac == 6)
		data->nb_meals = ft_atoi(av[5]);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_iteration, NULL);
	pthread_mutex_init(&data->mut_getter, NULL);
	return (allocate_memory(data));
}
