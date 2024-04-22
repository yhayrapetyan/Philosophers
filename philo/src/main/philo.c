/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:03 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:52:05 by yuhayrap         ###   ########.fr       */
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
	if (pthread_create(&data->alive_monit, NULL, &alive_monitoring, data))
		return ;
	if (get_nb_meals(data) != -1 && \
		pthread_create(&data->full_monit, NULL, &full_monitoring, data))
		return ;
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
	if (pthread_join(data->alive_monit, NULL))
		return ;
	if (nb_meals != -1 && pthread_join(data->full_monit, NULL))
		return ;
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
	init_data(&data, ac, av);
	init_philos(&data);
	init_forks(&data);
	create_threads(&data);
	join_threads(&data);
	clean_data(&data);
	return (0);
}
