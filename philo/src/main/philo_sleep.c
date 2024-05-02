/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:17 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/04/22 13:52:19 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_sleep(t_philo *philo)
{
	// set_philo_state(philo, SLEEPING);
	print_message(philo->data, philo->id, SLEEP);
	ft_usleep(get_sleep_time(philo->data));
	return (0);
}
