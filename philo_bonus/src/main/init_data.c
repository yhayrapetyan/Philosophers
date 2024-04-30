/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:33:51 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 16:33:51 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*init_philo(t_data *data, int id)
{
	char	*philo_id;
	char	*temp_id;

	temp_id = ft_itoa(id);
	philo_id = ft_strjoin("/philo_", temp_id);
	free(temp_id);
	if (!philo_id)
	{
		clean_data(data, 1);//need to check id
		ft_error("Allocation failed\n", 18);
	}
	sem_unlink(philo_id);
	data->philo.sem_philo = sem_open(philo_id, O_CREAT, 0644, 1);
	data->philo.id = id;
	update_last_meal_time(data);
	return (philo_id);
}

static int	init_semaphores(t_data *data)
{
	sem_unlink("/death");
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/data");
	data->sem_forks = sem_open("/forks", O_CREAT, 0644, data->nb_philos);
	if (data->sem_forks == SEM_FAILED)
		return (printf("SEM FAILED\n"));
	data->sem_print = sem_open("/print", O_CREAT, 0644, 1);
	if (data->sem_print == SEM_FAILED)
	{
		sem_close(data->sem_forks);
		return (printf("SEM FAILED\n"));
	}
	data->sem_data = sem_open("/data", O_CREAT, 0644, 1);
	if (data->sem_data == SEM_FAILED)
	{
		sem_close(data->sem_forks);
		sem_close(data->sem_data);
		return (printf("SEM FAILED\n"));
	}
	data->sem_death = NULL;
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	data->nb_philos = ft_atoi(av[1]);
	data->die_time = (u_int64_t) ft_atoi(av[2]);
	data->eat_time = (u_int64_t) ft_atoi(av[3]);
	data->sleep_time = (u_int64_t) ft_atoi(av[4]);
	data->nb_meals = -1;
	if (ac == 6)
		data->nb_meals = ft_atoi(av[5]);
	data->philo.data = data;
	data->philo.nb_meals_had = 0;
	data->philo.state = START;
	return (init_semaphores(data));
}
