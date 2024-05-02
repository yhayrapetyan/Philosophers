/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:48:22 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:48:24 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_data *data, int id, char *message)
{
	uint64_t	time;
	// int			can_prt;

	time = get_time() - get_start_time(data);
	// can_prt = can_print(data);
	pthread_mutex_lock(&data->mut_print);
	// if (can_prt == 1 && get_philo_state(&data->philos[id - 1]) != DEAD)
	if (get_philo_state(&data->philos[id - 1]) != DEAD)
		printf("%llu %d %s\n", time, id, message);
	pthread_mutex_unlock(&data->mut_print);
}
