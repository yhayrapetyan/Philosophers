/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:33:01 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 16:33:03 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_state	get_philo_state(t_data *data)
{
	t_state	state;

	sem_wait(data->philo.sem_philo);
	state = data->philo.state;
	sem_post(data->philo.sem_philo);
	return (state);
}
