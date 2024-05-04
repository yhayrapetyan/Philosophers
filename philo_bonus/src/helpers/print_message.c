/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:30:37 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 16:30:37 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_message(t_data *data, char *message)
{
	sem_wait(data->sem_print);
	printf("%llu %d %s\n", get_time() - data->start_time,
		data->philo.id, message);
	sem_post(data->sem_print);
	return (0);
}
