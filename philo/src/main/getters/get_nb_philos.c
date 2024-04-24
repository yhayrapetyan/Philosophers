/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:49:59 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:50:01 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_nb_philos(t_data *data)
{
	int	nb;

	pthread_mutex_lock(&data->mut_getter);
	nb = data->nb_philos;
	pthread_mutex_unlock(&data->mut_getter);
	return (nb);
}
