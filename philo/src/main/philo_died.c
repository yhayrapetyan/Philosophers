/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_died.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:12 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:52:14 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_died(t_philo *philo)
{
	if (get_time() - get_last_eat_time(philo) > get_die_time(philo->data))
	{
		// printf("%d last_eat_t = %llu\n",philo->id, get_time() - get_last_eat_time(philo));
		// printf("die_t = %llu\n", get_die_time(philo->data));
		// set_philo_state(philo, DEAD);
		return (1);
	}
	return (0);
}
