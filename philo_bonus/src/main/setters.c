/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:17:38 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/05/04 16:18:03 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_philo_state(t_data *data, t_state state)
{
	sem_wait(data->philo.sem_philo);
	data->philo.state = state;
	sem_post(data->philo.sem_philo);
}

void	update_last_meal_time(t_data *data)
{
	sem_wait(data->philo.sem_philo);
	data->philo.last_eat_time = get_time();
	sem_post(data->philo.sem_philo);
}
