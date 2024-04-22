/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:49:18 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:49:20 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	can_print(t_data *data)
{
	int	can_print;

	pthread_mutex_lock(&data->mut_print);
	can_print = data->can_print;
	pthread_mutex_unlock(&data->mut_print);
	return (can_print);
}
