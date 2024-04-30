/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_last_meal_time.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:33:20 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 16:33:21 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	update_last_meal_time(t_data *data)
{
	sem_wait(data->philo.sem_philo);
	data->philo.last_eat_time = get_time();
	sem_post(data->philo.sem_philo);
}
