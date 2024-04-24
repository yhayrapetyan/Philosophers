/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_iterate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:49:04 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:49:07 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	can_iterate(t_data *data)
{
	int	can_iterate;

	pthread_mutex_lock(&data->mut_getter);
	can_iterate = data->can_iterate;
	pthread_mutex_unlock(&data->mut_getter);
	return (can_iterate);
}
