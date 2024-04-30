/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:45:41 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 17:46:04 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	get_id(t_data *data)
{
	int	id;

	sem_wait(data->sem_data);
	id = data->philo.id;
	sem_post(data->sem_data);
	return (id);
}
