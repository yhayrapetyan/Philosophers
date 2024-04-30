/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <yuhayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:33:16 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/30 16:33:17 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_philo_state(t_data *data, t_state state)
{
	sem_wait(data->philo.sem_philo);
	data->philo.state = state;
	sem_post(data->philo.sem_philo);
}
