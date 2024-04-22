/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:27 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:52:29 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop_processes(t_data *data)
{
	int		i;
	int		nb_philos;
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
