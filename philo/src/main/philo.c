/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:03 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/05/01 19:13:07 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	i = 0;
	nb_philos = get_nb_philos(data);
	data->start_time = get_time();
	while (i < nb_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL,
				&routine, &data->philos[i]))
			return ;
		i++;
	}
}

void	join_threads(t_data *data)
{
	int	i;
	int	nb_meals;
	int	nb_philos;

	i = 0;
	nb_meals = get_nb_meals(data);
	nb_philos = get_nb_philos(data);
	while (i < nb_philos)
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
	if (init_data(&data, ac, av) != 0)
		return (1);
	init_philos(&data);
	init_forks(&data);
	create_threads(&data);
	while (1)
	{
		if (full_monitoring((void *)&data) == NULL || \
			alive_monitoring((void *)&data) == NULL)
		// if (alive_monitoring((void *)&data) == NULL || \
		// 	full_monitoring((void *)&data) == NULL)
			break ;
	}
	join_threads(&data);
	clean_data(&data);
	return (0);
}
